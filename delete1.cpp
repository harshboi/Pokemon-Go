#include "header.h"

void check(int *a,int *c){
   *a = 10;
   c = a;
   cout << *c << endl;
}

int return_x(int *a){
   cout << "&a is " << &a << endl;
   return &a;
}

int main(){
   int *a,b=10,*c = new int;
   *c = 100;
   a = &b;
   check(a,c);
   cout << *c << endl;
   int *d = return_x(c);
}
