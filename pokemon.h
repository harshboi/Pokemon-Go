#pragma once
#include "event.h"

class pokemon:public event{
	protected:
		string name,evolvee,evolve1;
		int type;
	public:
		// virtual ~pokemon();
		virtual string get_name() = 0;
		virtual void set_name() = 0;
    virtual int catch_probability() = 0;
    virtual void print_message() = 0;
		virtual void set_evolve_name() = 0;
		virtual void set_type(int); // Does not work if not set to 0
		// virtual int get_num_mega_stones();
		int get_pokeballs();
		virtual void increment_pokemon();
		virtual string get_base_name();
		virtual void mega_evolve() = 0;
		virtual int get_game_over() = 0;
		virtual string get_my_type() = 0;
		virtual int get_done() = 0;
		virtual void set_num_caught() = 0;
		virtual void get_num_caught() = 0;
};
