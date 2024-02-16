CC=g++
CFLAGS=-Wall -Wextra -Ofast -march=native -mtune=native
CEXTRAFLAGS=-funroll-loops -finline-functions -fomit-frame-pointer -falign-loops -falign-labels
SRCS=node.cpp game.cpp main.cpp 
OBJS=$(SRCS:.cpp=.o)
TARGET=eightPuzzleGame

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(CEXTRAFLAGS) $(OBJS) -o $(TARGET)

%.o: %.
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -f $(OBJS) $(TARGET)

help:
	@echo ""
	@echo "To compile $(TARGET), type: "
	@echo "make [OPT=option]"
	@echo ""
	@echo "Supported options:"
	@echo ""
	@echo "help 				> Display this message."
	@echo "all 				> Only compile."
	@echo "clean 				> Clean the Makefile directory from old files."
	@echo ""
	@echo "Do you have any doubts? See the Makefile."
	@echo ""

.PHONY: clean help
