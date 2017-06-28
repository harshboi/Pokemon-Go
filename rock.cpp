#include "rock.h"

rock::rock(){ //
  // if(num_for_evolve == 0){
  //   evolve = "Charizard"
  //   evolve1 = "Mega Charizard";
  // }
  // else{
  //   evolve = "Rayquaza 1";
  //   evolve1 = "Mega Rayquaza";
  // }
//  type 1 = ""
  evolve = 0;
  ready = 0;
  done = 0;
  my_type = "r";
  num_caught = 0;
}




string rock::get_name(){
  return name;
}

void rock::set_name(){
  int x = rand()%2;
  if(x==0){
    base_name = "Onix";
    name = "Onix";
    evolvee = "Steelix";
    evolve1 = "Mega Steelix";
    set_type(1);
  }
  else{
    base_name = "Geodude";
    name = "Geodude";
    evolvee = "Graveler";
    evolve1 = "Golem";
    set_type(2);
  }
}

void rock::set_evolve_name(){
  if(evolve == 0){
    name = evolvee;
    evolve = 1;
    cout << "Name is" << name << endl;
  }
}

int rock::catch_probability(){
  int x = (rand()%100)<75;
  return x; // Change to x;
}

void rock::print_message(){
  set_name();  // Sets the name over here
  cout << "Capture the " << name << " nearby ";
}

void rock::set_type(int x){
  type = x;
}

int rock::my_num_type = 0;

void rock::increment_pokemon(){
    rock::my_num_type += 1;
    cout << "inside increment pokemon" << endl;
    ready = 1;
    set_evolve_name();
    set_num_caught();
  // else if(type == 2){
    // my_num_type2 += 1;
  // }
}
// rock::~rock(){}

string rock::get_base_name(){
  return base_name;
}

void rock::mega_evolve(){
  if(ready == 1 && done == 0){
    done = 1;
    name = evolve1;
  }
}

int rock::get_game_over(){
  return ready;
}

string rock::get_my_type(){
  return my_type;
}

int rock::get_done(){
  return done;
}

void rock::get_num_caught(){
  if(num_caught == 0){
    cout << "Number of " << base_name << "'s caught is 1" << endl;
  }
  else{
    cout << "Number of " << base_name << "'s caught is " << num_caught << endl;
  }
}

void rock::set_num_caught(){
  num_caught += 1;
}
