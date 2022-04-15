## compiler
CXX = g++ -std=c++11
CXXFLAGS = -pedantic -g

mainALL: inlab7b.o storeClassb.o
	$(CXX) $(CXXFLAGS) inlab7b.o storeClassb.o -o mainALL

inlab7b.o: inlab7b.cc storeClassb.h
	$(CXX) $(CXXFLAGS) -c inlab7b.cc

storeClassb.o: storeClassb.cc storeClassb.h
	$(CXX) $(CXXFLAGS) $(CXXFLAGS) -c storeClassb.cc

clean:
	$(RM) mainALL *.o
