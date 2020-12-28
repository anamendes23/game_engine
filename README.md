# Game Engine Series

This project is a combination of following "The Cherno" game engine series on Youtube, along with reading the book "Game Engine Architecture" by Jason Gregory. My goal is to go through all the tutorials and use the book as a theorerical suplement and eventually learn enough to make my own changes to the game engine.

## Roadmap

What will the game engine have?

### Entrypoint

What happens when the application is launched?
For the entry point, the main method was encapsulated inside the engine project called GameEngine. The client will use the Sandbox project for game development.

### Logging

This will be a way to log events so the engine can communicate with the user. The goal is for the application to be the most client-facing possible. Because of that, it is nice to use a color code to differenciate the severity of the messages. It is also good to know where the log is coming from. Because of the extension of this work, an external library is used for printing messages - [spdlog](https://github.com/gabime/spdlog).

### Premake

The game engine is currently build for Windows only. In order to have the option available to build the application to other platforms, [premake](https://github.com/premake/premake-core) will be used.

### Event System

Application needs to receive events to dispatch them to layers. The Window class will receive these events and communicate with Application class.
Set up a call back function to pass event data to the Application.

The event system was implemented for application, mouse, key, and window events.

### Precompiled Headers

Have a header file containing all the libraries and precompile them when building the solution. This makes it faster to build the solution.

### Application Layer

Code that deals with application lifecycle and events.

### Window Layer

Target for graphics rendering and input events come from.
For web, there's a surface layer, not window.

Implementation: using GLFW, because it is cross-platform.
Window abstraction: use one class per platform. The design was made this way to leave the possibility to use win32 API instead of GLFW for Windows in the future. 

* Inputs
* Events

Windows generate events, like when the mouse clicks on a point, a key is pressed on the keyboard, etc. The Event and Window layers were created, so now we must link those two. To do that, implement GLFW event callbacks.

### Layers

Layers in a game engine is similar to layers in Photoshop, for example. This layer stack will determine the order in which things are drawn on the screen. Layers in a game engine are also applicable to events and update logic.

Possible layers:

* game layer (root)
* debug layer
* UI layer

### ImGui

ImGui runs through the Game Engine to render things on the screen. This will be implemented to assist debugging the application.

### Renderer

Renders the graphics on the screen.

### Render API abstraction

### Debugging support

Log, profiling system, etc.

### Scripting language

### Memory systems

Memory allocation and tracking usage.

### Entity-Component System (ECS)

Create game objects and modularize them.

### Physics

### File I/O, VFS

### Build system

 
