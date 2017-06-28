#include "world.h"
// #define DEBUG

world::world(const world &other){
  start_x = other.start_x;
  start_y = other.start_y;
  p_stop_x = other.p_stop_x;
  p_stop_y = other.p_stop_y;
  ash = other.ash;
  size_x = other.size_x;
  size_y = other.size_y;
  capture = other.capture;
  megastones = other.megastones;
  num_allocations = other.num_allocations;
  grid = new location*[size_x];
  for(int i = 0;i<size_x;i++){
    grid[i] = new location [size_y];
  }
  for(int i = 0;i<size_x;i++){
    for(int j = 0;j<size_y;j++){
      grid[i][j] = other.grid[i][j];
    }
  }
  for(int i = 0;i<capture;i++){
    my_p[i] = other.my_p[i]; // same as my_p[i][0] = other.my_p[i][0]
  }
}

void world::operator=(const world &other){
  if(grid != NULL){
    delete [] grid;
  }
  if(my_p != NULL){
    delete [] my_p;
  }
  start_x = other.start_x;
  start_y = other.start_y;
  p_stop_x = other.p_stop_x;
  p_stop_y = other.p_stop_y;
  ash = other.ash;
  size_x = other.size_x;
  size_y = other.size_y;
  capture = other.capture;
  megastones = other.megastones;
  num_allocations = other.num_allocations;
  for(int i = 0;i<size_x;i++){
    for(int j = 0;j<size_y;j++){
      grid[i][j] = other.grid[i][j];
    }
  }
  for(int i = 0;i<capture;i++){
    my_p[i] = other.my_p[i]; // same as my_p[i][0] = other.my_p[i][0]
  }
}

world::world(){
  srand(time(NULL));
  capture = 0;
  megastones = 1;
  num_allocations = 0;
  ash.set_num_pokeballs(10);
  cave_x = 100;
}

world::~world(){
  for(int i = 0;i<size_x;i++){
    delete [] grid[i]; // Why the difference
  }
  delete [] grid;
  for(int i = 0;i<1;i++){
    delete [] my_p[i];   // Why is it different
  }
  delete [] my_p;
}

void world::create_grid(int x,int y){
  grid = new location *[x];
  size_x = x;
  size_y = y;
  for(int i = 0;i<y;i++){
    grid[i] = new location[y];
  }
  for(int i = 0;i<x;i++){
    for(int j = 0;j<y;j++){
     grid[i][j].set_trainer(0);
     grid[i][j].set_pos(" "); // DEBUG
    //  cout << "I is " << i << " J IS " << j << endl;
    }
  }
}

int world::check_full(){
  string x;
  x = grid[x_coordinate][y_coordinate].get_pos();
  if(x == "f"){
    catch_pokemon("f");
  }
  else if(x == "p"){
    catch_pokemon("p");
   }
  else if(x == "r"){
    catch_pokemon("r");
  }
  else if(x == "c"){
    mega_evolve();
  }
  else if(x == "po"){
    int balls;
    balls = grid[x_coordinate][y_coordinate].get_event()->get_pokeballs();
    ash.set_num_pokeballs(balls);
    cout << "You have " << ash.get_num_pokeballs() << endl << endl;

  }
}

int world::get_pokeballs(){}

int world::check_event(int x,int y){
  if(grid[x][y].get_pos() == " "){
    return 0;
  }
  else
    return 1;
}

int world::check_event_rep(){
  int answer = check_event(x_coordinate,y_coordinate);
  // cout << "answer is " << answer << endl;
  return answer;
}

void world::set_event(){
   if(cave_x != 100){
   grid[cave_x][cave_y].set_pos(" ");
   grid[cave_x][cave_y].del();
   grid[p_stop_x][p_stop_y].set_pos(" "); // Error over here
   grid[p_stop_x][p_stop_y].del();
   //   grid[p_stop_x][p_stop_y].set_event(" ");
  }
  string x = " ";
  int loop = 1,a,b,c,d;
  for(int i = 0;i<5;i++){
    while(loop == 1){
      a = rand()%(size_x);
      b = rand()%(size_y);
      c = rand()%(4);
      loop = check_event(a,b);
    }
    if(c == 0){
      x = "f";
    }
    else if(c == 1){
      x = "p";
    }
    else if(c == 2){
      x = "r";
    }
    grid[a][b].set_pos(x);
    grid[a][b].set_event(x);
    loop = 1;
    // num_allocations += 1;
  }
  while(loop == 1){
    a = rand()%size_x;
    b = rand()%size_y;
    loop = check_event(a,b);
  }
  cave_x = a;
  cave_y = b;
  loop = 1;
  grid[a][b].set_pos("c");
  grid[a][b].set_event("c");
  while(loop == 1){
    a = rand()%size_x;
    b = rand()%size_y;
    loop = check_event(a,b);
    p_stop_x = a;
    p_stop_y = b;
  }
  grid[a][b].set_event("po");
  grid[a][b].set_pos("po");
}

void world::set_start(){
  start_x = rand()%(size_x);
  start_y = rand()%(size_y);
  x_coordinate = start_x;
  y_coordinate = start_y;
}

void world::print_grid(){
  for(int i = 0;i<size_x;i++){
    for(int j = 0;j<size_y;j++){
      grid[i][j].set_trainer(0);
    }
  }
  grid[x_coordinate][y_coordinate].set_trainer(1);
  for(int i = 0;i<size_x;i++){
    for(int j = 0;j<size_y;j++){
      #ifdef DEBUG
      cout << "|" << grid[i][j].get_pos(); //<< "|";
      #endif
    }
    #ifdef DEBUG
    cout << endl;
    #endif
  }
  cout << endl;
  grid[x_coordinate][y_coordinate].set_trainer(1);
  for(int i = 0;i<size_x;i++){
    for(int j = 0;j<size_y;j++){
      cout << "|" << grid[i][j].get_train(); //<< "|";
    }
    cout << endl;
  }
}

void world::move(int x){
  cout << endl;
  cout << "Number of Pokeballs " << ash.get_num_pokeballs() << endl;
  if(x==0){ // UP
    x_coordinate -= 1;
  }
  else if(x==1){ // Down
    x_coordinate += 1;
  }
  else if(x==2){ // Left
    y_coordinate -= 1;
  }
  else if(x==3){ // Right
    y_coordinate += 1;
  }
}
// ****************This function called out in main **************//
void world::messages(){
  if(x_coordinate != size_x-1){
    if(grid[x_coordinate+1][y_coordinate].get_pos() != " "){
      grid[x_coordinate+1][y_coordinate].get_message();
    }
  }
  if((y_coordinate != size_y-1) && (grid[x_coordinate][y_coordinate+1].get_pos() != " ")){
    grid[x_coordinate][y_coordinate+1].get_message();
  }
  if((y_coordinate != 0) && (grid[x_coordinate][y_coordinate-1].get_pos() != " ")){
    grid[x_coordinate][y_coordinate-1].get_message();
  }
  if(x_coordinate != 0 && (grid[x_coordinate-1][y_coordinate].get_pos() != " ")){
    grid[x_coordinate-1][y_coordinate].get_message();
  }
}

void world::catch_pokemon(string x){
  int try1 = 1,probability;
  cout << "do you want to catch the " << grid[x_coordinate][y_coordinate].get_event()->get_name() << endl;
  cin >> try1;
  if(ash.get_num_pokeballs()>0){
  while(try1 == 1){
    if(ash.get_num_pokeballs()==0){
      cout << "Sorry insufficient number of pokeballs" << endl;
      // run_away(x);
      // cout << "ATLGHBKFB" <<endl;
      break;
    }
    ash.use_pokeballs();
    probability = grid[x_coordinate][y_coordinate].get_event()->catch_probability();
    // cout <<" probability  is " << probability << endl;
    cout << "Number of pokeballs " << ash.get_num_pokeballs() << endl;
    if(probability == 1){
      cout << "Pokemon caught " << endl;
      add_pokemon();
      // Add function for decrementing the number of pokeballs
      break;
    }
    cout << "Pokemon could not be caught, try again (1 to try): " << endl;
    cin >> try1;
    }
    if(probability != 1){ //
      run_away(x);
    }
  }
  else{
    cout << "Insufficient Pokeballs" << endl;
    run_away(x);
  }
}

void world::run_away(string x){
  int loop = 1,a,b;
  while(loop == 1){
    a = rand()%size_x;
    b = rand()%size_y;
    loop = check_event(a,b);
    if(x_coordinate == a && y_coordinate == b){
      loop = 1;
    }
  }
  grid[a][b].set_pos(x);
  grid[a][b].set_event(x);
  // grid[x_coordinate][y_coordinate].get_event();// = NULL;
  // grid[x_coordinate][y_coordinate].clean();
  // grid[x_coordinate][y_coordinate].del();
  grid[x_coordinate][y_coordinate].set_pos(" ");
  grid[x_coordinate][y_coordinate].del(); // set_event(" ")
}

void world::refill_away(string x){
  int loop = 1,a,b;
  while(loop == 1){
    a = rand()%size_x;
    b = rand()%size_y;
    loop = check_event(a,b);
    if(x_coordinate == a && y_coordinate == b){
      loop = 1;
    }
  }
  grid[a][b].set_pos(x);
  grid[a][b].set_event(x);
  // grid[x_coordinate][y_coordinate].get_event();// = NULL;
//  grid[x_coordinate][y_coordinate].clean();
}

int world::already_captured(){
  string name;
  int counter = 0;
  name = grid[x_coordinate][y_coordinate].get_event()->get_base_name();
  for(int i = 0;i<capture;i++){
    // for(int j = 0;j<6;j++){
    if(my_p[i]->get_base_name() == name){
      counter = 1;
    }
  }
  if(counter == 1){
    return 1;
  }
  else
    return 0;
}

void world::add_pokemon(){
  string x;int y;
  x = grid[x_coordinate][y_coordinate].get_event()->get_name();
  //    ash.add_pokemons(x);
  // }
  if(capture != 0 && already_captured() == 1){
    for(int i = 0;i<capture;i++){
      if(x == my_p[i]->get_base_name()){
        y = i;
      }
    }
    my_p[y]->increment_pokemon();
  } // my_p[0] = grid[x_coordinate][y_coordinate].get_event();
  else{
    my_p[capture] = grid[x_coordinate][y_coordinate].get_event();
    my_p[capture][0].set_num_caught();
    // my_p[capture]->increment_pokemon();
    // Assigns
    capture++;
  }
  // cout << "Capture is " << capture << endl;
  for(int i = 0;i<capture;i++){
    cout << my_p[i]->get_name() << endl;
    my_p[i]->get_num_caught();
  }

  //grid[x_coordinate][y_coordinate].get_event();// = NULL;
  if(grid[x_coordinate][y_coordinate].get_pos() != "po" or grid[x_coordinate][y_coordinate].get_pos() != "c"){
    grid[x_coordinate][y_coordinate].clean();
    // grid[x_coordinate][y_coordinate].del(); // set_event(" ")
    grid[x_coordinate][y_coordinate].set_pos(" ");
    get_not_evolve();
  }
  // WHich Pokemon do you want to evolve
  // p[capture]->set_evolve_name(x); // Create this function
  // grid[x_coordinate][y_coordinate].set_null(); // Define it in location
  }

// Repopulates the array woth Pokemon that have not mega evolved
void world::get_not_evolve(){
  // cout << "SDCSDVJFISVNJDVNSJVNFNFVNSNVKNSFV" << endl;
  // int loop = 1,b = 0;
  // for(int k = 0;k<capture;k++){
  //   if(b == 1){break;}
  //   for(int i = 0;i<size_x;i++){
  //     if(b == 1){break;}
  //     for(int j = 0;j<size_y;j++){
  //       if(my_p[k]->get_my_type() == grid[i][j].get_pos() or my_p[k]->get_game_over() == 1){
  //         loop = 0;
  //         break;
  //       }
  //       else{
  //         b = 1;
  //       //  loop = 1;
  //       //  if(my_p[i]->get_game_over() != 1 && loop == 1){
  //       //    cout << "INSIDE" << endl;
  //           string xx = my_p[k]->get_my_type();
  //         //  cout << "X is " << capture << endl;
  //           run_away(xx);
  //         //}
  //         // break;
  //       }
  //     }
  //   }
  // }
  for(int k = 0;k<capture;k++){
    int counter = 0;
    string x = my_p[k]->get_my_type();
    for(int i = 0;i<size_x;i++){
      for(int j = 0;j<size_y;j++){
        if(x == grid[i][j].get_pos() || my_p[k]->get_game_over() == 1){
          counter = 1;
        }
      }
    }
    if(counter != 1){
      refill_away(x);
    }
  }
}

void world::mega_evolve(){
  // cout << "YOYOYO" << endl;
  //if(megastones == 1){
    for(int i = 0; i<capture;i++){
      my_p[i]->mega_evolve();
    }
    for(int i = 0;i<capture;i++){
      cout << my_p[i]->get_name() << endl;
    }
  //}
}

int world::all_my_evolve(){
  int evolve = 0;
  for(int i = 0;i<capture;i++){
    if(my_p[i][0].get_done() == 1){
      evolve = 1;
      // cout << "SEG Fault is here " << endl;
    }
    else{
      evolve = 0;
      return 0;
    }
  }
  return evolve;
}

int world::back_to_professor(){
  if(x_coordinate == start_x and y_coordinate == start_y){
    cout << "You met Professor Oak" << endl;
    ash.initial_balls();
    // Delete the cave and the poke stop
    return 0;
  }
  else
    return 1;
}

void world::play_again(){
  for(int i = 0;i<capture;i++){
    delete [] my_p[i];
  }
  delete [] my_p;
  capture = 0;
  num_allocations = 0;
}

int world::games_finished(){
  int finish = 0;
  num_allocations = 0;
  for(int i = 0;i<capture;i++){
    finish += my_p[i]->get_game_over();
  }
  for(int i = 0;i<size_x;i++){
    for(int j = 0;j<size_y;j++){
      // cout << " I is " << i << " j is " << j << endl;
      if(grid[i][j].get_pos() != " "){
        num_allocations += 1;
      }
    }
  }
  if(num_allocations == 2 && all_my_evolve() == 1){ //and finish == capture){
    cout << "Congratulations, you finished the game\n";
    // cout << "Enter 2 to play with the same configuration, 3 with a new config and 4 to quit";
    cout << "Go back to the professor" << endl;
    // cout << "Capture is " << capture << " Finish is " << finish << endl;
    int loop = back_to_professor();
    if(loop != 0){
      return 1;}
    else
      return 0;
  }
  else{
    finish = capture;
    return 1;
   }
}
