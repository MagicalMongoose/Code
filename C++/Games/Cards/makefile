CC=g++
CFLAGS=-c -g -O0 -std=c++11 -Wall
LDFLAGS=
SOURCES=poker.cpp deck.cpp card.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=poker

all: $(EXECUTABLE)

deps=$(patsubst %.o,%.d,$(OBJECTS))

-include $(deps)

DEPFLAGS=-MMD -MF $(@:.o=.d)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@ $(DEPFLAGS)

clean:
	rm -f core $(EXECUTABLE) $(OBJECTS) $(deps)
