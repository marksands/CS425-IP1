CXX = g++
SOURCES = main.cpp Observer.cpp ClockTimer.cpp AnalogClock.cpp DigitalClock.cpp
OBJECTS = $(SOURCES:.cpp=.o)
FLAGS = -g -O2 -c -Wall -fpermissive
EXECUTABLE = Observer

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	@$(CXX) $(OBJECTS) -o $@ -pg
	@echo "$(CXX) *.o -o $@"

.cpp.o:
	@$(CXX) $(FLAGS) $< -o $@ -pg
	@echo "$(CXX) $<"

clean:
	@rm -rf *.o gmon.out Observer