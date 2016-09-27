# The Gibson Engine
A 3D game engine. 

## Roadmap
Gibson is an iteratively developed project for the purpose of self-teaching game engine programming; the first major release will be scoped to focus on specializing 
the engine for developing a first person shooter game. The core focus of Gibson is the rendering subsystem, and to some extent the physics subsystem as well (the 1.0 release 
will use either a vastly oversimplified library just to get things moving, or a middleware solution like PhysX, whichever is easier).

## Directory structure
- src/ and headers/ - contains core .cpp and .h files
- shaders/ - contains GLSL shader files
- lib/ - libraries for GLFW and GLEW

## Building
You will need Git LFS to correctly pull the files in lib/. Once pulled, the only thing necessary should be to open the project in Visual Studio (VS2013 Express is the 
supported/tested version) and build/run.

## Design choices 
- `const` is used [as liberally as possible](http://www.gamasutra.com/view/news/169296/Indepth_Functional_programming_in_C.php), especially for function input arguments
- Use `const` variables instead of `#defines` 
- use `#pragma once` instead of `#ifndef` guards

## Conventions
- Use camel case (LikeThis, not_like_this or_LikeThis), except with globals (gThenDoThis)
- Return type, name, and args on one line followed by space and open brace:
```
void function (herp flerp) {

}
```
## License
Gibson is and always will be free, and therefore released under the GNU GPL v3.

## Special thanks / research material used
Jason Gregory - *Game Engine Architecture*  
Scott Meyers - *Effective C++*  
Herb Sutter, Andrei Alexandrescu - *C++ Coding Standards: 101 Rules, Guidelines, and Best Practices*  
Eric Haines - *Interactive 3D Graphics* (Udacity)  
Richard Jones, Richard Lins - *Garbage Collection: Algorithms for Automatic Dynamic Memory Management*