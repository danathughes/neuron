# The Gibson Engine
A 3D game engine

## Roadmap
Gibson is an iteratively developed project for the purpose of self-teaching game engine programming. See the Issues tab for a list of upcoming features.

## Directory structure
- `src/`- core source files, including main.cpp
- `headers/` - core headers, as well as subdirectories for test headers, abstract classes, and data headers
- `shaders/` - GLSL shader files
- `lib/` - libraries for GLFW and GLEW (requires LFS)
- `tests` - source files for unit tests.
- `Releases` - binaries for engine releases (requires LFS); **THIS WILL BE DEPRECATED SOON**

## Building
You will need Git LFS to correctly pull the files in lib/, regardless of the platform.

**Windows**  
Requires Visual Studio (2013 express). The libraries for GLFW and GLEW are in /lib, so you shouldn't have to install anything; simply open the vcxproj file in VS and build/run the project.

**Mac OSX (El Capitan)**  
Requires GNU Make, GCC, GLEW, and GLFW; the first two are Homebrew-able, see learnopengl.com for the other two. Once you have the dependencies met, run `make gibson`.

## Design choices
- `const` is used [as liberally as possible](http://www.gamasutra.com/view/news/169296/Indepth_Functional_programming_in_C.php), especially for function input arguments
- Use `const` variables instead of `#defines`
- use `#pragma once` instead of `#ifndef` guards
- No opaque one-liners or "optimizations" that exploit operator precedence, especially with pointers; this is not a coding competition and you don't look as cool as you think.

## Conventions
- Use capitalized camel case `LikeThis`, not `like_this` or `m_LikeThis`. Prefix globals with `g`, `gLikeThis`.
- In class declarations, declare public, then private, attributes first, then methods (except constructors/destructors - place them last); everything should be in decending alphabetized order.
- For pointers and references, use `Type* thing` or `Type& thing`, not `Type *thing`.
- Despite being technically unnecessary, if you call a method from within another method, preface it with `this->` so it's explicit that it's a method of that class.
- Return type, name, and args on one line followed by space and open brace:
```
void function (herp flerp) {

}
```
## Contributing
Feel free to send pull requests! I am always interested in collaborating.

## Questions
Contact me in some way through the links provided on [my personal page](https://jsgoller1.github.io).

## License
Gibson is and always will be free, and therefore released under the GNU GPL v3.

## Special thanks / research material used
Richard Jones, Richard Lins - *Garbage Collection: Algorithms for Automatic Dynamic Memory Management*  
Jason Gregory - *Game Engine Architecture*  
Scott Meyers - *Effective C++*  
Herb Sutter, Andrei Alexandrescu - *C++ Coding Standards: 101 Rules, Guidelines, and Best Practices*  
Joey de Vries - [Learn OpenGL Tutorials](http://learnopengl.com/)  
Eric Haines, Gundega Dekena - [*Interactive 3D Graphics*](https://www.udacity.com/course/interactive-3d-graphics--cs291) (Udacity)  
Ali Selcuk AKYUZ - [Linked Lists](http://www.cplusplus.com/articles/LACRko23/) (cplusplus.com)  
Michael Kissner - *[Writing a Game Engine from Scratch](http://www.gamasutra.com/blogs/MichaelKissner/20151027/257369/Writing_a_Game_Engine_from_Scratch__Part_1_Messaging.php)* (Gamasutra)  
John Carmack - [.plan files](https://github.com/Jsgoller1/john-carmack-plan-archive) and *[In-depth: Functional programming in C++](http://www.gamasutra.com/view/news/169296/Indepth_Functional_programming_in_C.php)* (Gamasutra)  
