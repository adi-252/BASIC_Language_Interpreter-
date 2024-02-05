CXX = g++
CPPFLAGS = -Wall -g -std=c++11

all: Interpreter
Interpreter: Interpreter.cpp LetStatement.o ProgramState.o PrintStatement.o EndStatement.o AddStatement.o SubStatement.o MultStatement.o DivStatement.o PrintAllStatement.o GotoStatement.o IfStatement.o GosubStatement.o ReturnStatement.o DotStatement.o
	$(CXX) $(CPPFLAGS) $^ -o $@
LetStatement.o: LetStatement.cpp LetStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@
ProgramState.o: ProgramState.cpp ProgramState.h
	$(CXX) $(CPPFLAGS) -c $< -o $@
PrintStatement.o: PrintStatement.cpp PrintStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@
EndStatement.o: EndStatement.cpp EndStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@
AddStatement.o: AddStatement.cpp AddStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@
SubStatement.o: SubStatement.cpp SubStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@
MultStatement.o: MultStatement.cpp MultStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@
DivStatement.o: DivStatement.cpp DivStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@
PrintAllStatement.o: PrintAllStatement.cpp PrintAllStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@
GoToStatement.o: GotoStatement.cpp GotoStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@
ifStatement.o: IfStatement.cpp IfStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@
GosubStatement.o: GosubStatement.cpp GosubStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@
ReturnStatement.o: ReturnStatement.cpp ReturnStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@
DotStatement.o: DotStatement.cpp DotStatement.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f *.o

