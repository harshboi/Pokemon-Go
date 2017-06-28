// #include "header.h"
#include "pokemon.h"

class flying:public pokemon{
  protected:
    string message;
    // int type;  // Defined in Pokemon
    static int my_num_type;
    // static int my_num_type
    int evolve;
    string base_name;
    string my_type;
    int num_caught;
    int ready; // tells whether th pokemon evolved once
    int done;  // tells whether the mokemon mega evolved;
  //  string name;
  //  string evolve;
  //  string evolve1;
  public:
    // ~flying();
    flying();
    string get_my_type();
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
    string get_not_evolve();
    int get_done();
    void get_num_caught();
    void set_num_caught();
    // void catch_pokemon();
		// virtual void add_pokemon();
};
