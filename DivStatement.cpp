// DivStatement.cpp:
#include "DivStatement.h"
using namespace std;

DivStatement::DivStatement(string variableName, int value, bool varVal)              // Constructor 
    : m_variableName(variableName), m_value(value), m_varVal(varVal)
{}

DivStatement::DivStatement(string variableName, string variableValue2, bool varVal)  // Constructor 2 
    : m_variableName(variableName), m_variableName2(variableValue2), m_varVal(varVal)
{}

void DivStatement::execute(ProgramState * state, ostream &outf)
{
    if(m_varVal){       // EX. MERRY 2
        if(m_value != 0){
            int num1 = state->getMapValue(m_variableName); // access value associated with MERRY
            int result = num1/m_value;                   // div it by 2 = result
            state->addToMap(m_variableName, result);       // set LUKE's value to result
        }
        else{
            outf << "Divide by 0 exception" << endl;
            state->setCurrLine(0);
            return;
        }
    }
    else{               // EX. MERRY LUKE
        int num1 = state->getMapValue(m_variableName);  // access value associated with MERRY
        int num2 = state->getMapValue(m_variableName2); // access value associated with LUKE
        if(num2 != 0){    // IF denom is not 0
            int result = num1/num2;
            state->addToMap(m_variableName, result);        // Set LUKE's value to the result
        }
        else{             // OTHERWISE denom is 0...
            outf << "Divide by 0 exception" << endl;
            state->setCurrLine(0);         // serCurrLine to 0 so we can end program
            return;                        // then return out of funciton.
        }
    }
    int line = state->getCurrLine();
	line++;
	state->setCurrLine(line); 	// after Div's operations are done, sets currLine to the next line.
}

DivStatement::~DivStatement()       // Destructor
{}
