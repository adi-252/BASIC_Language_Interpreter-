// MultStatement.h:

// EX: MULT MERRY -2
// OR  MULT PENN PIPPEN

// FORMAT
// MULT + VAR + VAL
// MULT + VAR + VAR

#ifndef MULT_STATEMENT_INCLUDED
#define MULT_STATEMENT_INCLUDED

#include "Statement.h"
#include "ProgramState.h"

class MultStatement: public Statement
{
private:
    std::string m_variableName;
    int m_value;
    std::string m_variableName2;
    bool m_varVal;

public:
    MultStatement(std::string variableName, int value, bool varVal);
    MultStatement(std::string variableName, std::string variableName2, bool varVal);
    ~MultStatement();
    virtual void execute(ProgramState * state, std::ostream &outf);
};

#endif