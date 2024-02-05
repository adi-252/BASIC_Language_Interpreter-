// GosubStatement.h:

// EX: GOSUB 6
// OR  GOSUB 5 
// What if it's GOSUB -5

// FORMAT
// GOSUB + VAL
// Can't be just GOSUB followed by nothing else

#ifndef GOSUB_STATEMENT_INCLUDED
#define GOSUB_STATEMENT_INCLUDED

#include "Statement.h"
#include "ProgramState.h"

class GosubStatement: public Statement 
{
private:
    int m_value;

public:
    GosubStatement(int val);
    ~GosubStatement();
    virtual void execute(ProgramState * state, std::ostream &outf);
};

#endif