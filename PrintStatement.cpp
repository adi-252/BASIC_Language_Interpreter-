// PrintStatement.cpp:
#include "PrintStatement.h"
using namespace std;

PrintStatement::PrintStatement(std::string variableName)
	: m_variableName( variableName )
{}

void PrintStatement::execute(ProgramState * state, std::ostream &outf)
{
	
	outf << state->getMapValue(m_variableName) << endl;
	
	int line = state->getCurrLine();
	line++;
	state->setCurrLine(line); 	// after print's operations are done, sets currLine to the next line.
}

PrintStatement::~PrintStatement() 	// Destructor
{}