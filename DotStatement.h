// DotStatement.h

// EX: .
// . is followed by nothing else

#ifndef DOT_STATEMENT_INCLUDED
#define DOT_STATEMENT_INCLUDED

#include "Statement.h"
#include "ProgramState.h"

class DotStatement: public Statement
{
public:
    DotStatement();
    ~DotStatement();
    virtual void execute(ProgramState * state, std::ostream &outf);

};


#endif
