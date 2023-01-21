CC = g++
CFLAGS = -Wall -std=c++11

all: clean main

main: main.o nodeImpl.o
	$(CC) $(CFLAGS) -o main main.o nodeImpl.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

nodeImpl.o: nodeImpl.cpp
	$(CC) $(CFLAGS) -c nodeImpl.cpp

clean:
	rm -rf main *.o

