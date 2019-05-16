// You may use this private member function (aka method)

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
