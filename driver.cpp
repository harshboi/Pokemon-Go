/****************************************************** **
 ** Author: Harshvardhan Singh
 ** Date: 05/28/2017
 ** Description: Driver File (contains the main)
 ** Input: Will call teh function for the menu, command line
 ** arguments for taking in the size of the grid
 ** Output: Will out put the grid and the menu options and the answer
 to the option selected
 ** *****************************************************/
#pragma once
#include "world.h"

int* convert_to_int(char *a,char *b){
   int *array = new int [2];
   int x;
   int y;
   array[0] = atoi(a);
   array[1] = atoi(b);
   cout << "A[0] is " << array[0] << " A[1] is " << array[1] << endl;
   return(array);
}

int main(int argc,char *argv[]){
   int *a = new int[2];  // CHange this line;
   a = convert_to_int(argv[1],argv[2]);
   int y,loop = 1,dif_config = 2,answer = 0;
   while(dif_config == 2){
      world w;
      w.create_grid(a[0],a[1]);
      w.set_start();
      int same_config = 1;
      while(same_config == 1){
	 w.set_event();
	 while(loop == 1){
	    w.print_grid();
	    w.messages();
	    cout << endl;
	    cout << "up(0) or down(1) or left(2) or right(3)" << endl;
	    int x;
	    cin>>x;
	    cout << endl;
	    w.move(x);
	    y = w.check_event_rep();
	    // cout << " Y is " << y << endl;
	    if(y == 1){
	       w.check_full();
	    }
	    loop = w.games_finished();
	 }
	 break;
	 // 	cout << "Do you want to play again with the same configuration(1),different configuration(2) or quit";
	 // 	cin >> answer;
	 // 	loop = 1;
	 // 	same_config = answer; dif_config = answer;
	 // 	if(answer == 1)
	 // 	  w.play_again();
      }
      break;
   }
   delete [] a;
}
