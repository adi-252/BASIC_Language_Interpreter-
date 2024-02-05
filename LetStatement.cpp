// LetStatement.cpp:
#include "LetStatement.h"
using namespace std;

LetStatement::LetStatement(std::string variableName, int value)  	 // Constructor 
	: m_variableName( variableName ), m_value( value )
{}

// The LetStatement version of execute() should make two changes to the
// state of the program:
//
//    * set the value of the appropriate variable
//    * increment the program counter

void LetStatement::execute(ProgramState * state, ostream &outf)		// Execute function
{
	state->addToMap(this->m_variableName, this -> m_value);

	int line = state->getCurrLine();
	line++;
	state->setCurrLine(line);
}

LetStatement::~LetStatement()	 // Destructor 
{}