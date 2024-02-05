// SubStatement.h:

// EX: SUB MERRY 2
// OR  SUB MERRY PIPPIN

// FORMAT
// SUB + VAR + VAL
// SUB + VAR + VAR

#ifndef SUB_STATEMENT_INCLUDED
#define SUB_STATEMENT_INCLUDED

#include "Statement.h"
#include "ProgramState.h"

class SubStatement: public Statement
{
private:
    std::string m_variableName;
    int m_value;
    std::string m_variableName2;
    bool m_varVal;

public:
    SubStatement(std::string variableName, int value, bool varVal);
    SubStatement(std::string variableName, std::string variableName2, bool varVal);
    ~SubStatement();
    virtual void execute(ProgramState * state, std::ostream &outf);
};

#endif