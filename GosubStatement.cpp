// GosubStatement.cpp:
#include "GosubStatement.h"
using namespace std;


GosubStatement::GosubStatement(int val)
    : m_value(val)
{}

void GosubStatement::execute(ProgramState * state, ostream &outf)        // Execute Function
{
    if ((m_value < 1) || m_value > (state->getNumLines())){         // IF jump line to is out of bounds of program THEN quit
        outf << "Illegal jump instruction" << endl;
        state->setCurrLine(0);      // if currLine is < 0 then while loop in interpreter terminates
    }
    else{
        int stackLine = state->getCurrLine();
        state->addToStack(stackLine + 1);       // Add next line after current line to stack 

        state->setCurrLine(m_value);        // IF jump line is in bounds and valid THEN set currLine to jump line
    }
    

}

GosubStatement::~GosubStatement()       // Destructor
{}


