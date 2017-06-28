#include "header.h"

int *convert_to_int(char *a,char *b){
   int x,y;
   x = atoi(a);
   y = atoi(b);
}

int main(int argc,char *argv[]){
   int *a;
   cout << "argv[0] is " << argv[0] << " argv[1] is " << argv[1] << endl;
   a = convert_to_int(argv[0],argv[1]);
   string h[2][1];
   h[0][0] = "harsh";
   cout << h[0][0];
}
