#include "psychic.h"

psychic::psychic(){ //
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
  my_type = "p";
  num_caught = 0;
}

string psychic::get_name(){
  return name;
}

void psychic::set_name(){
  int x = rand()%2;
  if(x==0){
    base_name = "Mew";
    name = "Mew";
    evolvee = "Mewto";
    evolve1 = "Mega Mewto";
    set_type(1);
  }
  else{
    base_name = "Evee";
    name = "Evee";
    evolvee = "Vaporean";
    evolve1 = "Ultimate Vaporean";
    set_type(2);
  }
}

void psychic::set_evolve_name(){
  if(evolve == 0){
    name = evolvee;
    evolve = 1;
    cout << "Name is" << name << endl;
  }
}

int psychic::catch_probability(){
  int x = (rand()%100)<25;
  return x; // Change to x;
}

void psychic::print_message(){
  set_name();  // Sets the name over here
  cout << "Capture the " << name << " nearby ";
}

void psychic::set_type(int x){
  type = x;
}

int psychic::my_num_type = 0;

void psychic::increment_pokemon(){
    psychic::my_num_type += 1;
    cout << "inside increment pokemon" << endl;
    ready = 1;
    set_evolve_name();
    set_num_caught();
  // else if(type == 2){
    // my_num_type2 += 1;
  // }
}
// psychic::~psychic(){}

string psychic::get_base_name(){
  return base_name;
}

void psychic::mega_evolve(){
  if(ready == 1 && done == 0){
    done = 1;
    name = evolve1;
  }
}

int psychic::get_game_over(){
  return ready;
}

string psychic::get_my_type(){
  return my_type;
}

int psychic::get_done(){
  return done;
}

void psychic::get_num_caught(){
  if(num_caught == 0){
    cout << "Number of " << base_name << "'s caught is 1" << endl;
  }
  else{
    cout << "Number of " << base_name << "'s caught is " << num_caught << endl;
  }
}

void psychic::set_num_caught(){
  num_caught += 1;
}
