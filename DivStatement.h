// DivStatement.h:

// EX: DIV MERRY 2
// OR  DIV MERRY LUKE

// FORMAT
// DIV + VAR + VAR
// DIV + VAR + VAL

#ifndef DIV_STATEMENT_INCLUDED
#define DIV_STATEMENT_INCLUDED

#include "Statement.h"
#include "ProgramState.h"

class DivStatement: public Statement
{
private:
    std::string m_variableName;
    int m_value;
    std::string m_variableName2;
    bool m_varVal;

public:
    DivStatement(std::string variableName, int value, bool varVal);
    DivStatement(std::string variableName, std::string variableName2, bool varVal);
    ~DivStatement();
    virtual void execute(ProgramState * state, std::ostream &outf);
};

#endif