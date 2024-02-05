// MultStatement.cpp:
#include "MultStatement.h"
using namespace std;

MultStatement::MultStatement(string variableName, int value, bool varVal)              // Constructor 
    : m_variableName(variableName), m_value(value), m_varVal(varVal)
{}

MultStatement::MultStatement(string variableName, string variableValue2, bool varVal)  // Constructor 2 
    : m_variableName(variableName), m_variableName2(variableValue2), m_varVal(varVal)
{}

void MultStatement::execute(ProgramState * state, ostream &outf)
{
    if(m_varVal){       // EX. LUKE 3
        int num1 = state->getMapValue(m_variableName); // access value associated with LUKE
        int result = num1 * m_value;                   // Mult 3 to LUKE's Value = result
        state->addToMap(m_variableName, result);       // set LUKE's value to result
    }
    else{               // EX. LUKE ANAKIN
        int num1 = state->getMapValue(m_variableName);  // access value associated with LUKE
        int num2 = state->getMapValue(m_variableName2); // access value associated with ANAKIN
        int result = num1 * num2;
        state->addToMap(m_variableName, result);        // Set LUKE's value to the result
    }
    int line = state->getCurrLine();
	line++;
	state->setCurrLine(line); 	// after Mult's operations are done, sets currLine to the next line.
}

MultStatement::~MultStatement()        // Destructor 
{}