#include "header.h"

class trainer{
  protected:
    string *my_pokemon;
    // string *type;
    int num_gems;
    int evolved,evolved1;
    int pokeballs;
    int total, total_caught, num_evolutions, tot_num_evolutions;
  public:
    trainer();
    ~trainer();
    string *get_my_pokemon();
    void increment_num_gems(int);
    void evolve_pokemon();
    int get_num_pokeballs();      //
    void set_num_pokeballs(int);  //
    void use_pokeballs();         //
    void add_pokemons(string);     //
    void add_type();       //
    void initial_balls();
};
