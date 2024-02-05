// SubStatement.cpp:
#include "SubStatement.h"
using namespace std;

SubStatement::SubStatement(string variableName, int value, bool varVal)              // Constructor 
    : m_variableName(variableName), m_value(value), m_varVal(varVal)
{}

SubStatement::SubStatement(string variableName, string variableValue2, bool varVal)  // Constructor 2 
    : m_variableName(variableName), m_variableName2(variableValue2), m_varVal(varVal)
{}

void SubStatement::execute(ProgramState * state, ostream &outf)
{
    if(m_varVal){       // EX. SUB MERRY 2
        int num1 = state->getMapValue(m_variableName); // access value associated with MERRY
        int result = num1 - m_value;                   // Subtract 2 from MERRY's value = result
        state->addToMap(m_variableName, result);       // set MERRY's value to result
    }

    else{               // EX. SUB MERRY PIPPIN
        int num1 = state->getMapValue(m_variableName);  // access value associated with MERRY
        int num2 = state->getMapValue(m_variableName2); // access value associated with PIPPIN
        int result = num1 - num2;
        state->addToMap(m_variableName, result);        // Set MERRY's value to the result
    }
    int line = state->getCurrLine();
	line++;
	state->setCurrLine(line); 	// after Sub's operations are done, sets currLine to the next line.
}


SubStatement::~SubStatement()
{}