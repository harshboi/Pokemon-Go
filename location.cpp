#include "location.h"


location::location(const location &other){
  pos = other.pos;
  train = other.train;
  set_event(pos);
  e = other.e;
}

void location::operator=(const location &other){
  pos = other.pos;
  train = other.train;
  if(e != NULL){
    delete [] e;
  }
  e = other.e;
}

location::location(){}

location::~location(){
//  delete e;
}

void location::del(){
  delete e;
}

void location::clean(){
  e = NULL;
}

string location::get_train(){
  return train;
}

event *location::get_event(){
  return e;
}

void location::set_event(string x){
  // cout << "Setting Event" << endl;
  if(x == "f"){
    e = new flying;
    // cout << "Setting Event" << endl;
  }
  else if(x == "p"){
    e = new psychic;
    // cout << "Setting Event" << endl;
  }
  else if(x == "r"){
    e = new rock;
    // cout << "Setting Event" << endl;
  }
  else if(x == "c"){
    e = new cave;
    // cout << "Setting Event" << endl;
  }
  else if(x == "po"){
    e = new pokestop;
    // cout << "Setting Event" << endl;
  }
  // Addition over here
  else if(x == " "){
    try{
  //    delete e;
    }
    catch(...){
      cout << "OOOOHOHOHOHOHOHoHOOHOHOHOHAAAGAGAGAGAG" << endl;
    }
    // cout << "E deleted" << endl;
  }
}

void location::set_trainer(int x){
  if(x==1)
    train = "X";
  else
    train = " ";
}

void location::set_pos(string x){
  pos = x;
}

string location::get_pos(){
  return pos;
}

void location::get_message(){
  e->print_message();
}
