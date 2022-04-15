## compiler
CXX = g++ -std=c++11
CXXFLAGS = -pedantic -g
Target = date
To = $(Target).o
Th = $(Target).h
Tcpp = $(Target).cpp

mainALL: $(Target)_main.o $(To)
	$(CXX) $(CXXFLAGS) $(Target)_main.o $(To) -o mainALL

$(To): $(Tcpp) $(Th)
	$(CXX) $(CXXFLAGS) -c $(Tcpp)

$(Target)_main.o: $(Target)_main.cpp $(Th)
	$(CXX) $(CXXFLAGS) -c $(Target)_main.cpp
clean:
	$(RM) mainALL *.o
