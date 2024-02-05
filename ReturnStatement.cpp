// ReturnStatement.cpp:

#include "ReturnStatement.h"
using namespace std;

ReturnStatement::ReturnStatement()
{}

void ReturnStatement::execute(ProgramState * state, std::ostream &outf)
{
    if(state->stackEmpty()){        // IF stack is empty THEN exit the program
        state->setCurrLine(0);
    }
    else{
        // IF stack is not empty THEN..
        int line = state->getStackTop();  
        state->setCurrLine(line);       // Sets current line to the line at the top of stack 

        state->popStack();              // Pops that line from the top of the stack
    }
}

ReturnStatement::~ReturnStatement()
{}