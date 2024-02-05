// GotoStatement.cpp:
#include "GotoStatement.h"
using namespace std;

GotoStatement::GotoStatement(int val)       // Constructor
    : m_value(val)
{}

void GotoStatement::execute(ProgramState * state, ostream &outf)        // Execute Function
{
    if ((m_value < 1) || m_value > (state->getNumLines())){         // IF jump line to is out of bounds of program THEN quit
        outf << "Illegal jump instruction" << endl;
        state->setCurrLine(0);      // if currLine is < 0 then while loop in interpreter terminates
    }
    else{
        state->setCurrLine(m_value);     // IF jump line to is in bounds and valid THEN set currLine to jump line
    }     
}

GotoStatement::~GotoStatement()       // Destructor
{}


