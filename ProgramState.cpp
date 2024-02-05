// ProgramState.cpp:
#include "ProgramState.h"
using namespace std;


ProgramState::ProgramState(int numLines)
	: m_numLines(numLines), m_currLine(0)
{}

void ProgramState::setCurrLine(int line)
{
    m_currLine = line;
}

int ProgramState::getCurrLine()
{
    return m_currLine;
}

void ProgramState::addToMap(string var, int val)
{   
    // If var not found then it adds to map.
    if(this->m_dataMap.find(var) == this->m_dataMap.end()){
        this->m_dataMap.insert(pair<string, int>(var, val));
    }
    else{
        m_dataMap[var] = val; //  Otherwise, if found it updates the value in map
    }
}

int ProgramState::getMapValue(std::string var)
{
    if(this->m_dataMap.find(var) == this->m_dataMap.end()){     //if var is not in the map then add it to the map with val 0
        this->addToMap(var, 0);
    }
    else{     // If var is in the map then return m_dataMap[var]
        return m_dataMap[var];
    }
    return m_dataMap[var];
}


std::map<string, int> ProgramState::copyMap()
{
    return m_dataMap;
}

int ProgramState::getNumLines()
{
    return m_numLines;
}

void ProgramState::addToStack(int val)
{
    this->m_stackLines.push(val);
}

int ProgramState::getStackTop()
{
    return m_stackLines.top();
}

void ProgramState::popStack()
{
    m_stackLines.pop();
}

bool ProgramState::stackEmpty()
{
    return m_stackLines.empty();
}

