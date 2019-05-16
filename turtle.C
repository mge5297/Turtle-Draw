/**********************************************
* Program:  turtle.C                          *
* Author:                        *
* Date:                               *
*                                             *
* Abstract: Driver program for the turtle     *
**********************************************/
#include <iostream>
#include "Turtle.h"

using namespace std;

int main() {
  Turtle myTurtle;		// turtle object defined
  
  if (myTurtle.Open()){		// open the input file
    myTurtle.ProcessInput();	// execute the commands on the file
    myTurtle.DisplayFloor();	// display the picture drawn
  }
  else {
    cerr << "Turtle's input file could not be opened" << endl;
    return 1;
  }
  
  return 0;
}

