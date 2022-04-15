## compiler
CXX = g++ -std=c++11
CXXFLAGS = -pedantic -g
TARGET = Student

mainALL: student_main.o $(TARGET).o
	$(CXX) $(CXXFLAGS) student_main.o $(TARGET).o -o mainALL

student_main.o: student_main.cpp $(TARGET).h
	$(CXX) $(CXXFLAGS) -c student_main.cpp

$(TARGET).o: $(TARGET).cpp $(TARGET).h
	$(CXX) $(CXXFLAGS) -c $(TARGET).cpp

clean:
	$(RM) mainALL *.o
