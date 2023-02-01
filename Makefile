# This Makefile specifies how to build the eight puzzle game
# with all the dependencies. 
# - author: Filipondios
# - version 25.01.2023
# Please modify carefully this file.

CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=node.cpp main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
HEADERS=node.h coordinate.h algorithm.h
EXECUTABLE=8-puzzle-solver

all: $(SOURCES) $(HEADERS) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o: $(HEADERS)
	$(CC) $(CFLAGS) $< -o $@

$(HEADERS): $(SOURCES)

clean:
	rm -rf $(EXECUTABLE) $(OBJECTS)
	$(MAKE) all

# Before running 'make', you can run 'make clean', so you delete the old
# project files like .o files and the project executable. 
#
# This last action will clean the current project directory so you only 
# have the source files like .cpp and .h.

cleanAll:
	rm -rf $(OBJECTS)

# To clean the current dir from the .o files, just run make clean-dir,
# so you'll only have the executable (project sample) in the project dir.

install:
	@if [ "$(shell uname -s)" = "Linux" ]; then \
		echo "Running make in Linux. Copiying 'eightgame' to /usr/bin/"; \
		sudo cp $(EXECUTABLE) /usr/bin/; \
		sudo cp -r 8-puzzle-solver.6.gz /usr/share/man/man6; \
	elif [ "$(shell uname -s)" = "Darwin" ]; then \
		echo "Running make in MacOS. Copiying 'eightgame' to /usr/local/bin/"; \
		sudo cp $(EXECUTABLE) /usr/local/bin/; \
	else \
		echo "Unknown OS. 'Eightgame' won't be installed"; \
	fi

# You can also 'install' the project if you are using a Linux or
# MacOS. To install the project, run 'make install' but if you haven't
# compiled the project yet, just run 'make' and 'make install' or 'make clean'
# and 'make install' or directly 'make clean install'.
