#include "location.h"
#include "trainer.h"
// #inlcude ""

class world{
  protected:
    char what; // Specified what's at the array;
    int start_x,start_y,cave_x,p_stop_x,cave_y,p_stop_y;
    int x_coordinate,y_coordinate;
    location **grid;
    trainer ash;
    int size_x,size_y;
    flying f1,f2;
    rock r1,r2;
    psychic p1,p2;
    event **my_p = new event *[8];  // Use this
    int capture;
    int megastones;
    int num_allocations;
  public:
    world(const world &);
    void operator=(const world &);
    world();
    ~world();
    void set_start();
    void set_coordinates(int,int);
    void set_event();  // Initializes the Grid
    int check_event(int,int);
    void add_pokemon(); // Create a check for already captured pokemon
    // If a caught pokemon appears again, evolve it using the fire function.
    void evolve_pokemon(string);
    void create_grid(int,int);
    void print_grid();
    int check_full();
    void run_away(string);
    void move(int); // 0-UP,1-DOWN,2-LEFT,3-RIGHT
    void messages();
    void catch_pokemon(string);
    int check_event_rep();
    void catch_pokemon();//{   // Try event if error
    int already_captured();
    int get_pokeballs();
    void mega_evolve();
    int games_finished();
    int back_to_professor();
    void get_not_evolve();
    int all_my_evolve();
    void refill_away(string);
    void play_again();
    //   p[capture] = grid[x_coordinate][y_coordinate].get_event();
    //   // Assigns
    //   capture++;
    //   // WHich Pokemon do you want to evolve
    //   int x;
    //   // p[capture]->set_evolve_name(x); // Create this function
    //   // grid[x_coordinate][y_coordinate].set_null(); // Define it in location
    // }
};
