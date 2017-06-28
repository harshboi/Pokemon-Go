#include "trainer.h"

trainer::~trainer(){
    delete [] my_pokemon;
    // for(int i = 0;i<12;i++){
}

trainer::trainer(){
  pokeballs = 0;
  num_gems = 0;
  total = 0;
  total_caught = 0;
  my_pokemon = new string [12];
  for(int i = 0;i<12;i++){
    my_pokemon[i] = "0";
  }
}

int trainer::get_num_pokeballs(){
  return pokeballs;
}

void trainer::set_num_pokeballs(int x){
  pokeballs += x;
}

void trainer::initial_balls(){
  pokeballs = 10;
}

void trainer::use_pokeballs(){
  pokeballs -= 1;
}

void trainer::add_pokemons(string x){
  total += 1;
  my_pokemon[total] = x;
}

void trainer::add_type(){

}
