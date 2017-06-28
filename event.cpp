/* World

flying a;
a.name = " sc";
pokemon p;
event *b = &p;
 */

 #include "event.h"

event::event(){
  srand(time(NULL));
}

int event::get_num_mega_stones(){
  return 0;
}

int event::catch_probability(){}

void event::print_message(){}

string event::get_name(){}

void event::set_name(){}

void event::set_evolve_name(){}

int event::get_pokeballs(){}

void event::set_type(int){}

void event::increment_pokemon(){}

string event::get_base_name(){}

void event::mega_evolve(){}

int event::get_game_over(){}

string event::get_my_type(){}

int event::get_done(){}

void event::set_num_caught(){}

void event::get_num_caught(){}

// Commebt the Destructor for a weird error
// event::~event(){}

//void event::

// void event::catch_pokemon(){}

// void event::add_pokemon(){}

// void event::increment_cave(){}
