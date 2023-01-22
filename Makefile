# This Makefile specifies how to build the eight puzzle game
# with all the dependencies. 
# - author: Filipondios
# - version 20.01.2023
# Please modify carefully this file.

CC = g++ # Compiler
CFLAGS = -Wall -std=c++11 # Flags

# Clean old build files before compiling. Then use
# all the available cores to compile
all: clean main
	make -j $(shell nproc) main

main: main.o nodeImpl.o
	$(CC) $(CFLAGS) -o main main.o nodeImpl.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

nodeImpl.o: nodeImpl.cpp
	$(CC) $(CFLAGS) -c nodeImpl.cpp

# How to clean: all .o files
clean:
	rm -rf main *.o
