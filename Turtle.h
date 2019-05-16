/**********************************************
* Program:  Turtle.h                           *
* Author:   Michael Elkins                     *
* Date:  2/14/19                             *
*                                             *
* Abstract:   *
*            *
**********************************************/
#include <iostream>
#include <fstream>
using namespace std;
class Turtle {
		public:
			Turtle();
			bool Open();
			void ProcessInput();
			void DisplayFloor();
		private:
			char floor[20][20];			//Storage for array
			int trow;					//turtle row
			int tcol;					//turtle column
			char pen;                   // keeps track of if pen is up or down
			ifstream inFile;
			int getDigits(string instruction);
			void execute(string instructions);
			void Pup(string instructions);
			void Pdown(string instructions);
};



Turtle::Turtle() {
	//Pre: None
	//Post:Constructor, variables initialized
	//Purpose:Array displaying the floor and integers for the turtles location , boolean for pen up or down
	
	trow = 0;
	tcol = 0;
	pen = 'U';
	//filling the array
	for(int r = 0; r < 20; r++){
		for(int c = 0; c < 20; c++){
			
			floor[r][c] = ' ';
		}
		
	}
	
}

bool Turtle::Open(){
	//Pre:None
	//Post:chosen file loaded in
	//Purpose:loads in the list of instructions for the turtle to follow
	cout << "What is the name of the file?" << endl;
	string file;
	cin >> file;
	inFile.open(file.c_str());
	
	if(inFile.fail()){
		return false;
	}
	return true;



}


void Turtle::DisplayFloor() {
	//Pre:instructions executed
	//Post:Floor Printed
	//Purpose:Floor Printed
	
	//nested for loop printing Floor
	for(int r = 0; r < 20; r++){
		for(int c = 0; c < 20; c++){
			if(floor[r][c] == 0){
				cout << " ";
				
			}
			else
				cout << floor[r][c];
		}
		cout << endl;
	}
	
}


void Turtle::ProcessInput(){
	//Pre:File must be loaded into infile
	//Post:All commands from file have been executed
	//Purpose: Reads all commands amd calls appropraite method, or gives error if invalid command
	string next;
	getline(inFile,next);
	while(!inFile.eof()){
		//process this command
		if(next[0] != 'N' && next[0] != 'E' && next[0] != 'S' && next[0] != 'W' && next[0] != 'U' && next[0] != 'D')
		{
			cerr << "Invalid command." << endl;  //The first letter in the line is not N S E W or U D
		}
		else{
			execute(next); 
		}
		getline(inFile,next); //move to next command
	}
}

void Turtle::execute(string instructions){
	//Pre:Given valid command
	//Post:calls appropriate function depending on whether the pen is up or down 
	//or lifts or puts pen down if command is U or D
	//Purpose:call appropriate function
	
	if(instructions[0] == 'D' || instructions[0] =='U'){
		pen = instructions[0];
	}
	else{
		if (pen == 'U'){
			Pup(instructions);
			
		}
		
		if (pen == 'D'){
			Pdown(instructions);
			
		}
		
		
		
	}
	
	
}

void Turtle::Pup(string instructions){
	//Pre:valid instructions while pen up given
	//Post:instructions executed or error given if turtle leaves the floor
	//Purpose:Have the turtle move the appropriate direction and distance if valid
	
	int dist = getDigits(instructions);		//getting distance turtle will move
	
	//going up
	if(instructions[0] == 'N'){
		if(trow - dist < 0){
			cerr << "That is off the floor!" << endl;
		}
		else{
			trow = trow - dist;
		}
		
	}
	
	//going down
	if(instructions[0] == 'S'){
		if(trow + dist > 20){
			cerr << "That is off the floor!" << endl;
		}
		else{
			trow = trow + dist;
		}
		
	}
	
	//going right
	if(instructions[0] == 'E'){
		if(tcol + dist > 20){
			cerr << "That is off the floor" << endl;
		}
		else{
			tcol = tcol + dist;
		}
		
	}
	
	//going left
	if(instructions[0] == 'W'){
		if(tcol - dist < 0){
			cerr << "That is off the floor" << endl;
		}
		else{
			tcol = tcol - dist;
		}
		
	}
	
}

void Turtle::Pdown(string instructions){
	//Pre:valid instructions while pen up given
	//Post:instructions executed or error given if turtle leaves the floor
	//Purpose:Have the turtle move the appropriate direction and distance if valid, leaving behind asterisks
	int dist = getDigits(instructions);		//getting distance turtle will move
	
	//going up
	if(instructions[0] == 'N'){
		if(trow - dist < 0){
			cerr << "That is off the floor!" << endl;
		}
		else{
			for(int i = 0; i < dist ; i++){
				floor[trow][tcol] = '*';
				trow = trow - 1;
				
			}
		}
		
	}
	
	//going down
	if(instructions[0] == 'S'){
		if(trow + dist > 20){
			cerr << "That is off the floor!" << endl;
		}
		else{
			for(int i = 0; i < dist ; i++){
				floor[trow][tcol] = '*';
				trow = trow + 1;
				
			}
		}
		
	}
	
	//going right
	if(instructions[0] == 'E'){
		if(tcol + dist > 20){
			cerr << "That is off the floor" << endl;
		}
		else{
			for(int i = 0; i < dist ; i++){
				floor[trow][tcol] = '*';
				tcol = tcol + 1;
				
			}
		}
		
	}
	
	//going left
	if(instructions[0] == 'W'){
		if(tcol - dist < 0){
			cerr << "That is off the floor" << endl;
		}
		else{
			for(int i = 0; i < dist ; i++){
				floor[trow][tcol] = '*';
				tcol = tcol - 1;
				
			}
		}
		
	}
	
}
	
int Turtle::getDigits(string instruction)
// pre:  instruction is a string for an N, S, E, or W command
// post: if it's a valid command, it returns the number of positions to
//       move, otherwise it returns -1

// purpose:  This is a private member function that you can copy into your Turtle.h file.  
//            It will take a string (one line from the input file) as a parameter and
//            pick out the number of positions to move and return it.  
//            If there is a problem with that number, it will return a -1.

{
	if ((instruction.length() < 3))
		return -1;
	if (!isdigit(instruction[2]))
        	return -1;
	if ((instruction.length() == 3) || !isdigit(instruction[3])){
		return (instruction[2] - '0');
	}
	return (10 * (instruction[2] - '0')  +  (instruction[3] - '0'));
}	
	


