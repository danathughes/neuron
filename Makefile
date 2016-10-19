#######################################################################
# Configuration

# CC specifies which compiler we're using
CC = g++

# COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -S -std=c++11 -Wall -pedantic -c

FILE_TYPE = -m32

# LINKER_FLAGS specifies the libraries we're linking against
# Cocoa, IOKit, and CoreVideo are needed for static GLFW3.
LINKER_FLAGS = -framework OpenGL -lglfw3 -lglew

# OBJ_NAME specifies the name of our exectuable
OBJ_NAME = main

# SRC specifies which files to compile as part of the project
SRC_PATH = ./src/

# INCLUDE_PATHS specifies the additional include paths we'll need
INCLUDE_PATHS = -I/usr/local/include -I/opt/X11/include -I./headers -I./shaders

# LIBRARY_PATHS specifies the additional library paths we'll need
LIBRARY_PATHS = -L/usr/local/lib -I/opt/X11/lib -I./libs

#######################################################################
# Commands

all: gibson

gibson: main.o Renderer.o Windower.o PoolAllocator.o
	$(CC)  main.o Renderer.o Windower.o PoolAllocator.o $(LINKER_FLAGS) $(FILE_TYPE) -o gibson

PoolAllocator.o:
	$(CC) $(SRC_PATH)PoolAllocator.cpp $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(FILE_TYPE) $(LINKER_FLAGS) -o PoolAllocator.o

Windower.o:
	$(CC) $(SRC_PATH)Windower.cpp $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(FILE_TYPE) $(LINKER_FLAGS) -o Windower.o 

Renderer.o:
	$(CC) $(SRC_PATH)Renderer.cpp $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(FILE_TYPE) $(LINKER_FLAGS) -o Renderer.o

main.o:
	$(CC) $(SRC_PATH)main.cpp $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(FILE_TYPE) $(LINKER_FLAGS) -o main.o

#all :
#	$(CC) $(SRC) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
#	rm -r $(OBJ_NAME).dSYM
#	./$(OBJ_NAME)

#build:
#	$(CC) $(SRC) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
#	rm -r $(OBJ_NAME).dSYM

#go:
#	./$(OBJ_NAME)

#clean:
#	rm $(OBJ_NAME)

