## compiler
CXX = g++ -std=c++11
CXXFLAGS = -pedantic -g

mainALL: inlab7a.o storeClassa.o
	$(CXX) $(CXXFLAGS) inlab7a.o storeClassa.o -o mainALL

inlab7a.o: inlab7a.cc storeClassa.h
	$(CXX) $(CXXFLAGS) -c inlab7a.cc

storeClassa.o: storeClassa.cc storeClassa.h
	$(CXX) $(CXXFLAGS) $(CXXFLAGS) -c storeClassa.cc

clean:
	$(RM) mainALL *.o
