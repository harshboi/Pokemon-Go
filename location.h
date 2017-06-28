// #include "header.h"
#pragma once
#include "flying.h"
#include "psychic.h"
#include "rock.h"
#include "cave.h"
#include "pokestop.h"
// #include "event.h"

class location{
  protected:
    event *e;
    string pos;  // Is for computation purposes
    string train; // Is for printing purposes
  public:
    ~location();
    location();
    location(const location &);
    void operator=(const location&);
    event * get_event();
    string get_train();
    string get_pos();
    void set_pos(string);
    void set_event(string); // WIll create a event over here.eg:e=new flying;
    void set_trainer(int);
    void create_event(string);
    void get_message();
    void clean();
    void del();
};
