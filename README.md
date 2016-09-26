# The Gibson Engine
A 3D game engine. 

## Roadmap
Gibson is an iteratively developed project for the purpose of self-teaching game engine programming; the first major release will be scoped to focus on specializing 
the engine for developing a first person shooter game. The core focus of Gibson is the rendering subsystem, and to some extent the physics subsystem as well (the 1.0 release 
will use either a vastly oversimplified library just to get things moving, or a middleware solution like PhysX, whichever is easier).

## Directory structure
- src/ and headers/ - contains core .cpp and .h files
- shaders/ - contains GLSL shader files

## Building
Gibson uses GLFW and GLEW to faciliate windowing; you will need to follow [the learnopengl.com instructions](http://learnopengl.com/#!Getting-started/Creating-a-window) for 
installing these. A better solution will be found eventually.

## Design choices 
- Everything must be const unless there is a good reason for it not to be (and a comment explaining why)

## Conventions
- Use camel case (LikeThis, not_like_this or_LikeThis), except with globals (gThenDoThis)
- Return type, name, and args on one line followed by space and open brace:
void function (herp flerp) {

}

## License
Gibson is and always will be free, and therefore released under the GNU GPL v3.

## Special thanks / research material used
Jason Gregory - *Game Engine Architecture*  
Scott Meyers - *Effective C++*  
Eric Haines - *Interactive 3D Graphics* (Udacity)  
Richard Jones, Richard Lins - *Garbage Collection: Algorithms for Automatic Dynamic Memory Management*

