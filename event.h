// #pragma once
#include "header.h"
#pragma once
// #include "cave.h"
// #include "flying.h"
// #include "location.h"
// #include "pokestop.h"
// #include "psychic.h"
// #include "rock.h"

class event{
   protected:
      int num_for_evolve;
      // string **grid;  // Put it in the pokemon class;  Print this with the players location
      // string **grid_rep;  // Replica for the actual grid. Will contain the places where events take place. Do not print this;
      //string message;
      // int total, total_caught;
      // int num_evolutions,tot_num_evolutions;
   public:
      event();
      // virtual ~event();
      virtual void print_message();
      // virtual void add_pokemon()=0;
      virtual int catch_probability();
      // Bottom two fnuctions called in flying,...,.... classes;
      virtual string get_name();
      virtual void set_name();
      virtual void set_evolve_name();
      virtual int get_num_mega_stones();
      virtual int get_pokeballs();
      virtual void set_type(int);
      virtual void increment_pokemon();
      virtual string get_base_name();
      virtual void mega_evolve();
      virtual int get_game_over();
      virtual string get_my_type();
      virtual int get_done();
      virtual void set_num_caught();
      virtual void get_num_caught();
      // virtual void increment_cave();
      // void back_to_professor();
      /////////////////////////////virtual void print_message();
      // void catch_em_all();   // Should be in the pokemon class
};
