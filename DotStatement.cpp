// DotStatement.cpp

#include "DotStatement.h"
using namespace std;

DotStatement::DotStatement()        // Constructor
{}

DotStatement::~DotStatement()       // Destructor 
{}

void DotStatement::execute(ProgramState * state, ostream &outf)		// Execute function
{
    state->setCurrLine(0);
}