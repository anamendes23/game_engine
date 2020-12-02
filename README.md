# Game Engine Series

## Roadmap

What will the game engine have?

### Entrypoint

What happens when the application is launched?
For the entry point, the main method was encapsulated inside the engine project called GameEngine. The client will use the Sandbox project for game development.

### Logging

This will be a way to log events so the engine can communicate with the user. The goal is for the application to be the most client-facing possible. Because of that, it is nice to use a color code to differenciate the severity of the messages. It is also good to know where the log is coming from. Because of the extension of this work, an external library is used for printing messages - [spdlog](https://github.com/gabime/spdlog).

### Premake

The game engine is currently build for Windows only. In order to have the option available to build the application to other platforms, [premake](https://github.com/premake/premake-core) will be used.

### Application Layer

Code that deals with application lifecycle and events.

### Window Layer

Target for graphics rendering and input events come from.
For web, there's a surface layer, not window.

* Inputs
* Events

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

 
