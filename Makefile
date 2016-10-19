#######################################################################
# Configuration

# CC specifies which compiler we're using
CC = g++

# COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -c -lstdc++ -Wall -pedantic -c

FILE_TYPE = -arch x86_64

# LINKER_FLAGS specifies the libraries we're linking against
# Cocoa, IOKit, and CoreVideo are needed for static GLFW3.
LINKER_FLAGS = -framework OpenGL -lglfw3 -lglew

# OBJ_NAME specifies the name of our exectuable
OBJ_NAME = main

# SRC specifies which files to compile as part of the project
SRC_PATH = ./src/

# INCLUDE_PATHS specifies the additional include paths we'll need
INCLUDE_PATHS = -I/opt/X11/include -I./headers -I./shaders
#-I/usr/local/include

# LIBRARY_PATHS specifies the additional library paths we'll need
LIBRARY_PATHS =  -I/opt/X11/lib -I./libs
#-L/usr/local/lib

#######################################################################
# Commands

all: gibson

gibson: main.o Renderer.o Windower.o PoolAllocator.o
	$(CC)  main.o Renderer.o Windower.o PoolAllocator.o $(LINKER_FLAGS) $(FILE_TYPE) -o gibson

PoolAllocator.o:
	$(CC) $(SRC_PATH)PoolAllocator.cpp $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(FILE_TYPE) -o PoolAllocator.o

Windower.o:
	$(CC) $(SRC_PATH)Windower.cpp $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(FILE_TYPE) -o Windower.o

Renderer.o:
	$(CC) $(SRC_PATH)Renderer.cpp $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(FILE_TYPE) -o Renderer.o

main.o:
	$(CC) $(SRC_PATH)main.cpp $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(FILE_TYPE) -o main.o

clean:
	rm *.o headers/*.gch
