# The Gibson Engine
A 3D game engine. Yes, it is named after William Gibson (and the supercomputer in Hackers).

## Design notes
Gibson will be an iteratively developed project; the long-term goal is to create The Engine To End All Engines - a competitively peformant multiplatform 3D game engine. Despite this naively lofty goal, the first major release will be scoped to focus on specializing the engine for developing a 3rd-person 3D hack-and-slash games. So,
- Gibson will use a message-bus architecture as described in [this gamasutra article](http://www.gamasutra.com/blogs/MichaelKissner/20151027/257369/Writing_a_Game_Engine_from_Scratch__Part_1_Messaging.php);
- The UI system will look bad;
- The keyboard will be the only supported form of input;
- AI will be vastly oversimplified and probably abuse A* searching, FSMs, and behavior trees;
- Physics will be supported initially by nVidia PhysX, and then be ported to a custom library using simple rigidbody physics and very basic collision detection;
- Rendering will be done at first via Ogre3D, and then ported to a simplistic library written against OpenGL only;
- Audio will consist of simple sounds with the Windows Core Audio APIs;
- There will be no multiplayer or networking support;
- Only x64 Windows will be supported;
- Garbage collection will be probably inefficient and half the time will crash the engine due to OOM errors arising from the fact that I shouldn't have changed majors from Philosophy to CS;

In the long term, I would like to develop:
- Generically usable procedural content generation as a core feature of the engine
- Support for cutting-edge physically based rendering techniques, especially efficient soft shadows.
- Efficient physics for difficult systems such as many particles, fluids, and realistic flight
- AI smart enough to murder you in your sleep without trying to navigate through walls
- VR support for both Oculus and Vive
- Support for FBX files
- Efficient and powerful garbage collection
- A multiplatform layer for running on 32bit Windows, OSX, and Linux
- Vulkan DX11, and DX12 support

# License
DFE is and always will be free, and therefore released under the GNU GPL v3.
