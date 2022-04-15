## compiler
CXX = g++ -std=c++11
CXXFLAGS = -pedantic -g
TARGET = sList

mainALL: $(TARGET)_main.o $(TARGET).o
	$(CXX) $(CXXFLAGS) $(TARGET)_main.o $(TARGET).o -o mainALL

$(TARGET)_main.o: $(TARGET)_main.cpp $(TARGET).h
	$(CXX) $(CXXFLAGS) -c $(TARGET)_main.cpp

$(TARGET).o: $(TARGET).cpp $(TARGET).h
	$(CXX) $(CXXFLAGS) -c $(TARGET).cpp

clean:
	$(RM) mainALL *.o
