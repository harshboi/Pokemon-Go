// #include "header.h"
#include "pokemon.h"

class rock:public pokemon{
  protected:
    string message;
    // int type;  // Defined in Pokemon
    static int my_num_type;
    // static int my_num_type
    int evolve;
    string base_name;
    int ready;
    int done;
    string my_type;
    int num_caught;
  //  string name;
  //  string evolve;
  //  string evolve1;
  public:
    // ~rock();
    rock();
    void set_type(int); //
    void set_name();
    string get_name();
    int catch_probability();
    void print_message();
    void set_evolve_name();
    void increment_pokemon();
    string get_base_name();
    void mega_evolve();
    int get_game_over();
    string get_my_type();
    int get_done();
    void set_num_caught();
		void get_num_caught();
    // void catch_pokemon();
		// virtual void add_pokemon();
};
