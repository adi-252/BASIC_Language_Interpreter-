// AddStatement.h:

// EX: ADD PENN TELLER
// OR  ADD MERRY -2

// FORMAT
// ADD + VAR + VAR
// ADD + VAR + VAL

#ifndef ADD_STATEMENT_INCLUDED
#define ADD_STATEMENT_INCLUDED

#include "Statement.h"
#include "ProgramState.h"

class AddStatement: public Statement
{
private:
    std::string m_variableName;
    int m_value;
    std::string m_variableName2;
    bool m_varVal;

public:
    AddStatement(std::string variableName, int value, bool varVal);
    AddStatement(std::string variableName, std::string variableName2, bool varVal);
    ~AddStatement();
    virtual void execute(ProgramState * state, std::ostream &outf);
};

#endif