// IfStatement.h:

// EX: IF 6
// OR  IF 5 
// OR  IF 5 
// OR  IF 5 
// OR  IF 5 
// OR  IF 5 

// FORMAT
// IF + VAL
// Can't be just IF followed by nothing else

#ifndef If_STATEMENT_INCLUDED
#define If_STATEMENT_INCLUDED

#include "Statement.h"
#include "ProgramState.h"

class IfStatement: public Statement 
{
private:
    std::string m_variableName;
    std::string m_op;
    int m_value;
    int m_jumpLine;

public:
    IfStatement(std::string var, std::string op, int val, int jumpLine);
    ~IfStatement();
    virtual void execute(ProgramState * state, std::ostream &outf);
};

#endif