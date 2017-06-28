#include "pokestop.h"

int pokestop::get_pokeballs(){
  num_pokeballs = rand()%8+3;
  cout << "You got " << num_pokeballs << " pokeballs" << endl << endl;
  return num_pokeballs;
}

void pokestop::print_message(){
  cout << "You see pokeballs nearby" << endl;
}

// void
