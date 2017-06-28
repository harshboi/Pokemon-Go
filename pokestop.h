// #include "header.h"
#pragma once
#include "event.h"

class pokestop:public event{
  protected:
    int num_pokeballs;
  public:
    int get_pokeballs();
    void print_message();
};
