CC = g++
LFLAGS = -std=c++11
CFLAGS = -c -Wall

SOURCES = main.cpp CommandDriver.cpp GenericTask.cpp Date.cpp ShoppingTask.cpp Event.cpp Homework.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE_NAME = Project2

all: $(EXECUTABLE_NAME)

$(EXECUTABLE_NAME): $(OBJECTS)
	$(CC) -o $(EXECUTABLE_NAME) $(OBJECTS)

.cpp.o:
	$(CC) $(CFLAGS) $(LFLAGS) $< -o $@

clean:
	$(RM) *.o *~ $(EXECUTABLE_NAME)
