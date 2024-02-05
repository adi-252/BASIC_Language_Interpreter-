// AddStatement.cpp:
#include "AddStatement.h"
using namespace std;

AddStatement::AddStatement(string variableName, int value, bool varVal)              // Constructor 
    : m_variableName(variableName), m_value(value), m_varVal(varVal)
{}

AddStatement::AddStatement(string variableName, string variableValue2, bool varVal)  // Constructor 2 
    : m_variableName(variableName), m_variableName2(variableValue2), m_varVal(varVal)
{}

// The AddStatement version of execute should make x changes 
// to program state:
//
//  * update the value of the appropriate variable 
//  * increment the program counter/ current line number 

void AddStatement::execute(ProgramState * state, ostream &outf)
{
    if(m_varVal){       // EX. LUKE 3
        int num1 = state->getMapValue(m_variableName); // access value associated with LUKE
        int result = num1 + m_value;                   // add 3 to it = result
        state->addToMap(m_variableName, result);       // set LUKE's value to result
    }
    else{               // EX. LUKE ANAKIN
        int num1 = state->getMapValue(m_variableName);  // access value associated with LUKE
        int num2 = state->getMapValue(m_variableName2); // access value associated with ANAKIN
        int result = num1 + num2;
        state->addToMap(m_variableName, result);        // Set LUKE's value to the result
    }
    int line = state->getCurrLine();
	line++;
	state->setCurrLine(line); 	// after Add's operations are done, sets currLine to the next line.
}

AddStatement::~AddStatement()      // Destructor 
{}


