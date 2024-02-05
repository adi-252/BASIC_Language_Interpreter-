// EndStatement.cpp

#include "EndStatement.h"
using namespace std;

EndStatement::EndStatement()        // Constructor
{}

EndStatement::~EndStatement()       // Destructor 
{}

void EndStatement::execute(ProgramState * state, ostream &outf)		// Execute function
{
    state->setCurrLine(0);
}