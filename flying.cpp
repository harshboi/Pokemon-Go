#include "flying.h"

flying::flying(){ //
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
  my_type = "f";
  num_caught = 0;
}

string flying::get_name(){
  return name;
}

void flying::get_num_caught(){
  if(num_caught == 0){
    cout << "Number of " << base_name << "'s caught is 1" << endl;
  }
  else{
    cout << "Number of " << base_name << "'s caught is " << num_caught << endl;
  }
}

void flying::set_num_caught(){
  num_caught += 1;
}

void flying::set_name(){
  int x = rand()%2;
  if(x==0){
    base_name = "Charmeleon";
    name = "Charmeleon";
    evolvee = "Charizard";
    evolve1 = "Mega Charizard";
    set_type(1);
  }
  else{
    base_name = "Rayquaza";
    name = "Rayquaza";
    evolvee = "Mega Rayquaza";
    evolve1 = "Ultimate Rayquaza";
    set_type(2);
  }
}

void flying::set_evolve_name(){
  if(evolve == 0){
    name = evolvee;
    evolve = 1;
    cout << "Name is" << name << endl;
  }
}

int flying::catch_probability(){
  int x = (rand()%100)<50;
  return x; // Change to x;
}

void flying::print_message(){
  set_name();  // Sets the name over here
  cout << "Capture the " << name << " nearby ";
}

string flying::get_my_type(){
  return my_type;
}

void flying::set_type(int x){
  type = x;
}

int flying::my_num_type = 0;

void flying::increment_pokemon(){
    flying::my_num_type += 1;
    // cout << "inside increment pokemon" << endl;
    ready = 1;
    set_evolve_name();
    set_num_caught();
  // else if(type == 2){
    // my_num_type2 += 1;
  // }
}
// flying::~flying(){}

string flying::get_base_name(){
  return base_name;
}

void flying::mega_evolve(){
  if(ready == 1 && done == 0){
    done = 1;
    name = evolve1;
  }
}

int flying::get_game_over(){
  // cout << "DONE IS " << done << endl;
  return ready;
}

int flying::get_done(){
  return done;
}
