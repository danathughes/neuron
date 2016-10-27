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
INCLUDE_PATHS = -I/opt/X11/include -I./headers -I./shaders -I./headers/lib -I./headers/classless -I./headers/tests
#-I/usr/local/include

# LIBRARY_PATHS specifies the additional library paths we'll need
LIBRARY_PATHS =  -I/opt/X11/lib -I./libs
#-L/usr/local/lib

#######################################################################
# Commands

# Make and run the tests
all_tests: tests.o GibVect3-tests.o GibVect3.o Triangle-tests.o Triangle.o MessageBus-tests.o MessageBus.o
	$(CC) tests.o GibVect3-tests.o GibVect3.o Triangle-tests.o Triangle.o MessageBus-tests.o MessageBus.o $(LINKER_FLAGS) $(FILE_TYPE) -o all_tests
	./all_tests

clean:
	(rm *.o; rm headers/*.gch; rm all_tests; rm gibson) || true

#Make and run the engine
gibson: main.o Renderer.o Windower.o PoolAllocator.o InputManager.o LLNode.o Triangle.o GibVect3.o SceneManager.o MessageBus.o
	$(CC)  main.o Renderer.o Windower.o PoolAllocator.o InputManager.o SceneManager.o MessageBus.o $(LINKER_FLAGS) $(FILE_TYPE) -o gibson
	./gibson

retest: clean all_tests

rerun: clean gibson

#######################################################################
# Test objects

GibVect3-tests.o:
	$(CC) $(TEST_PATH)GibVect3-tests.cpp $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(FILE_TYPE) -o GibVect3-tests.o

MessageBus-tests.o:
	$(CC) $(TEST_PATH)MessageBus-tests.cpp $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(FILE_TYPE) -o MessageBus-tests.o

Triangle-tests.o:
	$(CC) $(TEST_PATH)Triangle-tests.cpp $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(FILE_TYPE) -o Triangle-tests.o

tests.o:
	$(CC) $(TEST_PATH)tests.cpp $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(FILE_TYPE) -o tests.o

#######################################################################
# Project objects

GibVect3.o:
	$(CC) $(SRC_PATH)Vect3.cpp $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(FILE_TYPE) -o GibVect3.o

InputManager.o:
	$(CC) $(SRC_PATH)InputManager.cpp $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(FILE_TYPE) -o InputManager.o

LLNode.o:
	$(CC) $(SRC_PATH)LLNode.cpp $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(FILE_TYPE) -o LLNode.o

MessageBus.o:
	$(CC) $(SRC_PATH)MessageBus.cpp $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(FILE_TYPE) -o MessageBus.o

PoolAllocator.o:
	$(CC) $(SRC_PATH)PoolAllocator.cpp $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(FILE_TYPE) -o PoolAllocator.o

Renderer.o:
	$(CC) $(SRC_PATH)Renderer.cpp $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(FILE_TYPE) -o Renderer.o

SceneManager.o:
	$(CC) $(SRC_PATH)SceneManager.cpp $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(FILE_TYPE) -o SceneManager.o

Windower.o:
	$(CC) $(SRC_PATH)Windower.cpp $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(FILE_TYPE) -o Windower.o

Triangle.o:
	$(CC) $(SRC_PATH)Triangle.cpp $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(FILE_TYPE) -o Triangle.o

main.o:
	$(CC) $(SRC_PATH)main.cpp $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(FILE_TYPE) -o main.o
