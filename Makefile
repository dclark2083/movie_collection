# @file Makefile
# @author Kyle Byassee
# @date 2022-10-06
# @brief Makefile
# 
# A Makefile for phonebook

# The build target
TARGET = movieDB

# The compiler g++
CC = g++

# General compilation flags - Compiles with all errors and warnings
CFLAGS = -g -Wall -Wextra

# Compiles and Assembles without Linking
CFLAGS-C = $(CFLAGS) -c

# Compiles and Links
CFLAGS-O = $(CFLAGS) -o $(TARGET)

default: all
all: $(TARGET)

#The executable to be compiled
$(TARGET): library.o main.o
	$(CC) $(CFLAGS-O) library.o main.o

#The binary of the node class
library.o: library.cpp library.h
	$(CC) $(CFLAGS-C) library.cpp

#The binary of the main file
main.o: main.cpp library.h
	$(CC) $(CFLAGS-C) main.cpp

# Invoked with 'make clean'
clean:
	$(RM) $(TARGET) *.o *~
