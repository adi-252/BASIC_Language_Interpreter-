// Interpreter.cpp
#include "Statement.h"

#include "LetStatement.h"
#include "PrintStatement.h"
#include "DotStatement.h"
#include "PrintAllStatement.h"
#include "AddStatement.h"
#include "SubStatement.h"
#include "MultStatement.h"
#include "DivStatement.h"
#include "GotoStatement.h"
#include "EndStatement.h"
#include "GosubStatement.h"
#include "ReturnStatement.h"
#include "Ifstatement.h"

#include "ProgramState.h"
#include <vector>
#include <string>
#include <sstream> 
#include <fstream>
#include <cstdlib>
#include <iostream>


using namespace std;

// parseProgram() takes a filename as a parameter, opens and reads the
// contents of the file, and returns a vector of pointers to Statement.
void parseProgram(istream& inf, vector<Statement *> & program);

// parseLine() takes a line from the input file and returns a Statement
// pointer of the appropriate type.  This will be a handy method to call
// within your parseProgram() method.
Statement * parseLine(string line);

// interpretProgram() reads a program from the given input stream
// and interprets it, writing any output to the given output stream.
// Note:  you are required to implement this function!
void interpretProgram(istream& inf, ostream& outf);


// Turn in assignment with this main(), not the one provided in hw2_tests
int main()
{
        cout << "Enter BASIC program file name: ";
        string filename;
        getline(cin, filename);
        ifstream infile(filename.c_str());
        if (!infile)
        {
                cout << "Cannot open " << filename << "!" << endl;
                return 1;
        }
        interpretProgram(infile, cout);
}


void parseProgram(istream &inf, vector<Statement *> & program)
{
	program.push_back(NULL);
	
	string line;
	while( ! inf.eof() )
	{
		getline(inf, line);
		program.push_back( parseLine(line) );
	}
}

Statement * parseLine(string line)
{
	Statement * statement;	
	stringstream ss;
	int line_num;
	string type;
	string var;
	int val;

	ss << line;
	ss >> line_num;
	ss >> type;
	
	if ( type == "LET" )
	{
		ss >> var;
		ss >> val;
		// Note:  Because the project spec states that we can assume the file
		//	  contains a syntactically legal program, we know that
		//	  any line that begins with "LET" will be followed by a space
		//	  and then a variable and then an integer value.
		statement = new LetStatement(var, val);
	}

	// Incomplete;  TODO:  Finish this function!

	// EX: PRINT FINN
	else if ( type == "PRINT"){
		ss >> var; 							 // Parse in variable name
		statement = new PrintStatement(var); // Create Print statement with variable name
	}
	// EX: PRINTALL
	else if ( type == "PRINTALL"){
		statement = new PrintAllStatement();
	} 
	// EX: ADD LUKE 3 or ADD LUKE ANAKIN
	else if ( type == "ADD"){
		string var2;
		ss >> var;
		// Next item could be a variable or value. Try to store the second Item into an int. 
		ss >> val;
		if(ss.fail()){ 		// If ss fails then we know its a variable and not an int
			ss.clear();
			ss >> var2;
			statement = new AddStatement(var, var2, false);
		}
		else{ 				// If ss does not fail then extraction into (int) val was succesful
			statement = new AddStatement(var, val, true);
		}
	}
	// EX: SUB LEIA 3 or SUB LEIA PIPPEN
	else if ( type == "SUB"){
		string var2;
		ss >> var;
		// Next item could be a variable or value. Try to store the second Item into an int. 
		ss >> val;
		if(ss.fail()){ 		// If ss fails then we know its a variable and not an int
			ss.clear();
			ss >> var2;
			statement = new SubStatement(var, var2, false);
		}
		else{ 				// If ss does not fail then extraction into (int) val was succesful
			statement = new SubStatement(var, val, true);
		}
	}
	// EX: MULT REY LUKE
	else if ( type == "MULT"){
		string var2;
		ss >> var;
		// Next item could be a variable or value. Try to store the second Item into an int. 
		ss >> val;
		if(ss.fail()){ 		// If ss fails then we know its a variable and not an int
			ss.clear();
			ss >> var2;
			statement = new MultStatement(var, var2, false);
		}
		else{ 				// If ss does not fail then extraction into (int) val was succesful
			statement = new MultStatement(var, val, true);
		}
	}
	// EX: DIV FINN 2
	else if ( type == "DIV"){
		string var2;
		ss >> var;
		// Next item could be a variable or value. Try to store the second Item into an int. 
		ss >> val;
		if(ss.fail()){ 		// If ss fails then we know its a variable and not an int
			ss.clear();
			ss >> var2;
			statement = new DivStatement(var, var2, false);
		}
		else{ 				// If ss does not fail then extraction into (int) val was succesful
			statement = new DivStatement(var, val, true);
		}
	}
	// EX: GOTO 4
	else if ( type == "GOTO"){
		ss >> val;
		statement = new GotoStatement(val);
	}
	// EX: IF CHEWBACCA < 4 THEN 5
	else if ( type == "IF"){
		string op;
		string dummy; // dummy var to store THEN
		int jumpLine;
		
		ss >> var;
		ss >> op;
		ss >> val;
		ss >> dummy;
		ss >> jumpLine;
		statement = new IfStatement(var, op, val, jumpLine);
	}

	// EX: GOSUB 7
	else if ( type == "GOSUB"){
		ss >> val;
		statement = new GosubStatement(val);
	}
	// EX: RETURN
	else if ( type == "RETURN"){
		statement = new ReturnStatement();
	}
	// EX: END
	else if ( type == "END"){
		statement = new EndStatement();
	}
	// EX: .
	else if ( type == "."){
		statement = new DotStatement();
	}

	return statement;
}


void interpretProgram(istream& inf, ostream& outf){
	vector<Statement*> program;
	parseProgram(inf, program ); // parseProgram: use the infile to populate the program vector with statement* 
	
	// Incomplete;  TODO: Finish this function!

	ProgramState state(program.size()); 

	state.setCurrLine(1); 
	int i = 1;   	// i is the line to be executed. If negative quit program.

	while(i >= 1){
		program[i]->execute(&state, outf);	// Execute must do the task +  set m_currLine to the next line to be executed 
		i = state.getCurrLine();
	}

	// Program is now over

	// De-allocating all statements in program vector
	for(size_t j=0; j < program.size(); j++){
		delete program[j];
	}

}
