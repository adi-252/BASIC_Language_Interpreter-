// SubStatement.h:

// EX: END
// END is followed by nothing else

#ifndef END_STATEMENT_INCLUDED
#define END_STATEMENT_INCLUDED

#include "Statement.h"
#include "ProgramState.h"

class EndStatement: public Statement
{
public:
    EndStatement();
    ~EndStatement();
    virtual void execute(ProgramState * state, std::ostream &outf);
};

#endif