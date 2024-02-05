// PrintAllStatement.cpp:

#include "PrintAllStatement.h"
using namespace std;

PrintAllStatement::PrintAllStatement()      // Constructor 
{}

// The PrintAllStatement version of execute() should:
// * Use the state->m_dataMap to print all variables that have been added to the map
// * Increment m_currLine to the next line

void PrintAllStatement::execute(ProgramState * state, ostream &outf)
{
    map<string, int> duplicateMap = state->copyMap();

    map<string,int>::iterator it;

    for(it = duplicateMap.begin(); it != duplicateMap.end(); ++it){      // iterating through the vector 
        outf << it->first << " " << it->second << endl;
    }

    int line = state->getCurrLine();
	line++;
	state->setCurrLine(line);   // Increment line
}

PrintAllStatement::~PrintAllStatement()     // Destructor 
{}

