# This Makefile specifies how to build the eight puzzle game
# with all the dependencies. 
# - author: Filipondios
# - version 25.01.2023
# Please modify carefully this file.

CC=clang++
CFLAGS=-c -g -Wall -Wextra -Wunused
SOURCES=node.cpp algorithm.cpp main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=8solver

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE)

# Instead of running 'make', you can run 'make clean', so you delete the old
# project files like .o files and the project executable and generate the new executable. 

install:
	@if [ "$(shell uname -s)" = "Linux" ]; then \
		echo "Running make in Linux. Copiying 'eightgame' to /usr/bin/"; \
		sudo cp $(EXECUTABLE) /usr/bin/; \
		sudo cp -r 8-puzzle-solver.6 /usr/share/man/man6; \
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

PHONY: clean install
