// ProgramState.h
//
// CS 104
//
// The ProgramState class encapsulates the state of an executing Facile
// program.  The state of a BASIC program consists of three parts:
//
//    * The program counter, which specifies the line number of the
//      statement that will execute next.
//    * A map, as explained by the problem writeup.
//    * A stack of integers, which is used to hold return lines for GOSUB
//      statements.
//
// We've provided you a start on this class, but you'll need to add methods
// to it as you go along.  In particular, you'll need methods to access and
// modify the state; these methods will be called primarily by the various
// execute() methods in the Statement subclasses, to allow the execution of
// a statement to change the state of a program.  For example, executing a
// GOTO statement will cause the program counter to be changed.

#ifndef PROGRAM_STATE_INCLUDED
#define PROGRAM_STATE_INCLUDED

#include <stack>
#include <map>
#include <string>

class ProgramState
{
public:
	ProgramState(int numLines);

	// You'll need to add a variety of methods here.  Rather than trying to
	// think of what you'll need to add ahead of time, add them as you find
	// that you need them.

	void setCurrLine(int line);     			// Set m_currLine 
	int getCurrLine();							// Get m_currLine
	void addToMap(std::string var, int val);	// Insert <var, val> to m_dataMap if variable is not in map. If variable is in map then update val.
	int getMapValue(std::string var);			// Return the val corresponding to var
	std::map<std::string, int> copyMap();       // Return copy of m_dataMap
	int getNumLines();							// Returns number of lines in program
	void addToStack(int val);					// Adds line number to stack for RETURN use
	int getStackTop();							// Returns the top most value of the stack
	void popStack();							// Calls pop on stack
	bool stackEmpty();

private:
	int m_numLines;		// Total number of lines in program 
	int m_currLine;		// Curr line number being executed

	// MY CODE:

	std::stack<int> m_stackLines; 	  	   // stack of line numbers to return to. For the use of GOSUB statements and RETURN statements.
	std::map<std::string, int> m_dataMap;  // map that stores variable names and their corresponding values
};

#endif

