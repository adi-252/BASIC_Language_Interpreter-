// IfStatement.cpp:
#include "IfStatement.h"
using namespace std;

IfStatement::IfStatement(std::string var, std::string op, int val, int jumpLine)        // Constructor
    : m_variableName(var), m_op(op), m_value(val), m_jumpLine(jumpLine)
{}

void IfStatement::execute(ProgramState * state, ostream &outf)        // Execute Function
{
    // IF condition is met THEN jump to line
    // OTHERWISE go to next line
    int firstVal = state->getMapValue(m_variableName);

    if(m_op == "<"){       
        if(firstVal < m_value){     // Condition Met 
            if ((m_jumpLine < 1) || (m_jumpLine > state->getNumLines())){         // IF jump line to is out of bounds of program THEN quit
                outf << "Illegal jump instruction" << endl;
                state->setCurrLine(0);      // if currLine is < 0 then while loop in interpreter terminates
            }
            else{
                state->setCurrLine(m_jumpLine);     // IF jump line to is in bounds and valid THEN set currLine to jump line
            }
        }
        else{       // Condition not met, go to next line
            int line = state->getCurrLine();
            line++;
            state->setCurrLine(line);
        }
    }
    else if(m_op == "<="){    
        if(firstVal <= m_value){     // Condition Met 
            if ((m_jumpLine < 1) || (m_jumpLine > state->getNumLines())){         // IF jump line to is out of bounds of program THEN quit
                outf << "Illegal jump instruction" << endl;
                state->setCurrLine(0);      // if currLine is < 0 then while loop in interpreter terminates
            }
            else{
                state->setCurrLine(m_jumpLine);     // IF jump line to is in bounds and valid THEN set currLine to jump line
            }
        }
        else{       // Condition not met, go to next line
            int line = state->getCurrLine();
            line++;
            state->setCurrLine(line);
        }
    }
    else if(m_op == ">"){   
        if(firstVal > m_value){     // Condition Met 
            if ((m_jumpLine < 1) || (m_jumpLine > state->getNumLines())){         // IF jump line to is out of bounds of program THEN quit
                outf << "Illegal jump instruction" << endl;
                state->setCurrLine(0);      // if currLine is < 0 then while loop in interpreter terminates
            }
            else{
                state->setCurrLine(m_jumpLine);     // IF jump line to is in bounds and valid THEN set currLine to jump line
            }
        }
        else{       // Condition not met, go to next line
            int line = state->getCurrLine();
            line++;
            state->setCurrLine(line);
        }      
    }
    else if(m_op == ">="){        
        if(firstVal >= m_value){     // Condition Met 
            if ((m_jumpLine < 1) || (m_jumpLine > state->getNumLines())){         // IF jump line to is out of bounds of program THEN quit
                outf << "Illegal jump instruction" << endl;
                state->setCurrLine(0);      // if currLine is < 0 then while loop in interpreter terminates
            }
            else{
                state->setCurrLine(m_jumpLine);     // IF jump line to is in bounds and valid THEN set currLine to jump line
            }
        }
        else{       // Condition not met, go to next line
            int line = state->getCurrLine();
            line++;
            state->setCurrLine(line);
        }      
    }
    else if(m_op == "="){  
        if(firstVal == m_value){     // Condition Met 
            if ((m_jumpLine < 1) || (m_jumpLine > state->getNumLines())){         // IF jump line to is out of bounds of program THEN quit
                outf << "Illegal jump instruction" << endl;
                state->setCurrLine(0);      // if currLine is < 0 then while loop in interpreter terminates
            }
            else{
                state->setCurrLine(m_jumpLine);     // IF jump line to is in bounds and valid THEN set currLine to jump line
            }
        }
        else{       // Condition not met, go to next line
            int line = state->getCurrLine();
            line++;
            state->setCurrLine(line);
        }            
    }
    else if(m_op == "<>"){ 
        if(firstVal != m_value){     // Condition Met 
            if ((m_jumpLine < 1) || (m_jumpLine > state->getNumLines())){         // IF jump line to is out of bounds of program THEN quit
                outf << "Illegal jump instruction" << endl;
                state->setCurrLine(0);      // if currLine is < 0 then while loop in interpreter terminates
            }
            else{
                state->setCurrLine(m_jumpLine);     // IF jump line to is in bounds and valid THEN set currLine to jump line
            }
        }
        else{       // Condition not met, go to next line
            int line = state->getCurrLine();
            line++;
            state->setCurrLine(line);
        }             
    } 
}

IfStatement::~IfStatement()       // Destructor
{}


