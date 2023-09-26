# Compiler and flags for the program
CC = gcc
CFLAGS = -Wall -Werror -g -I../include

# Directory
SRCDIR = .

# Source file for the program
SRC = $(wildcard $(SRCDIR)/*.c)

# Target program
PROGRAM = hex_to_base64

all: $(PROGRAM)

$(PROGRAM): $(SRC) ../$(LIBRARY)
	$(CC) $(CFLAGS) -o $@ $(SRC) -L../ -lkrypter

clean:
	rm -f $(PROGRAM)

.PHONY: all clean