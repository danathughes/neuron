#######################################################################
# Configuration

# CC specifies which compiler we're using
CC = g++

# COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -c -std=c++11 -Wall -pedantic -c

FILE_TYPE = -arch x86_64

# LINKER_FLAGS specifies the libraries we're linking against
# Cocoa, IOKit, and CoreVideo are needed for static GLFW3.
LINKER_FLAGS = -framework OpenGL -lglfw3 -lglew

# OBJ_NAME specifies the name of our exectuable
OBJ_NAME = main

# SRC specifies which files to compile as part of the project
SRC_PATH = ./src/

# TEST specifies which files to compile as part of the tests
TEST_PATH = ./tests/

# INCLUDE_PATHS specifies the additional include paths we'll need
INCLUDE_PATHS = -I/opt/X11/include -I./headers -I./shaders
#-I/usr/local/include

# LIBRARY_PATHS specifies the additional library paths we'll need
LIBRARY_PATHS =  -I/opt/X11/lib -I./libs
#-L/usr/local/lib

#######################################################################
# Commands

rerun: clean run

recompile: clean all

run: all
	./gibson

all: gibson

gibson: main.o Renderer.o Windower.o PoolAllocator.o InputManager.o LLNode.o Triangle.o Vect3.o SceneManager.o
	$(CC)  main.o Renderer.o Windower.o PoolAllocator.o InputManager.o SceneManager.o $(LINKER_FLAGS) $(FILE_TYPE) -o gibson

all_tests: tests.o Vect3-tests.o Vect3.o
	$(CC) tests.o Vect3-tests.o Vect3.o $(LINKER_FLAGS) $(FILE_TYPE) -o all_tests
	./all_tests


#######################################################################
# Test objects

Vect3-tests.o:
	$(CC) $(TEST_PATH)Vect3-tests.cpp $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(FILE_TYPE) -o Vect3-tests.o

tests.o:
	$(CC) $(TEST_PATH)tests.cpp $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(FILE_TYPE) -o tests.o

#######################################################################
# Project objects

PoolAllocator.o:
	$(CC) $(SRC_PATH)PoolAllocator.cpp $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(FILE_TYPE) -o PoolAllocator.o

Windower.o:
	$(CC) $(SRC_PATH)Windower.cpp $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(FILE_TYPE) -o Windower.o

Renderer.o:
	$(CC) $(SRC_PATH)Renderer.cpp $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(FILE_TYPE) -o Renderer.o

InputManager.o:
	$(CC) $(SRC_PATH)InputManager.cpp $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(FILE_TYPE) -o InputManager.o

LLNode.o:
	$(CC) $(SRC_PATH)LLNode.cpp $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(FILE_TYPE) -o LLNode.o

Triangle.o:
	$(CC) $(SRC_PATH)Triangle.cpp $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(FILE_TYPE) -o Triangle.o

Vect3.o:
	$(CC) $(SRC_PATH)Vect3.cpp $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(FILE_TYPE) -o Vect3.o

SceneManager.o:
	$(CC) $(SRC_PATH)SceneManager.cpp $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(FILE_TYPE) -o SceneManager.o

main.o:
	$(CC) $(SRC_PATH)main.cpp $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(FILE_TYPE) -o main.o

clean:
	(rm *.o; rm headers/*.gch; rm all_tests; rm gibson) || true
