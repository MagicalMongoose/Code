## compiler
CXX = g++ -std=c++11
CXXFLAGS = -pedantic -g

EmailMainALL: EmailMain.o Email.o
	$(CXX) $(CXXFLAGS) EmailMain.o Email.o -o EmailMainALL

EmailMain.o: Email_main.cpp Email.h
	$(CXX) $(CXXFLAGS) -c Email_main.cpp

Email.o: Email.cpp Email.h
	$(CXX) $(CXXFLAGS) -c Email.cpp

clean:
	$(RM) EmailMainALL *.o
