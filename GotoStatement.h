// GotoStatement.h:

// EX: GOTO 6
// OR  GOTO 5 
// What if it's GOTO -5

// FORMAT
// GOTO + VAL
// What if it's just GOTO followed by nothing else

#ifndef GOTO_STATEMENT_INCLUDED
#define GOTO_STATEMENT_INCLUDED

#include "Statement.h"
#include "ProgramState.h"

class GotoStatement: public Statement 
{
private:
    int m_value;

public:
    GotoStatement(int val);
    ~GotoStatement();
    virtual void execute(ProgramState * state, std::ostream &outf);
};

#endif

