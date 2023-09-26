# Compiler and flags
CC = gcc
CFLAGS = -Wall -Werror -g -Iinclude

# Directories
SRCDIR = library
INCDIR = include
BUILDDIR = build
PROGDIR = programs
TESTDIR = tests

# Source files and object files
SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(patsubst $(SRCDIR)/%.c, $(BUILDDIR)/%.o, $(SRC))

# Target library
LIBRARY = libkrypter.a

all: $(LIBRARY) build_programs

lib: $(LIBRARY)

$(LIBRARY): $(OBJ)
	ar -rcs $@ $(OBJ)

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

build_programs:
	$(MAKE) -C $(PROGDIR) hex_to_base64

clean:
	rm -rf $(BUILDDIR) $(LIBRARY)
	$(MAKE) -C $(PROGDIR) clean

.PHONY: all clean
