# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.30.2/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.30.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/larrybanks/2D_Engine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/larrybanks/2D_Engine

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Running CMake cache editor..."
	/opt/homebrew/Cellar/cmake/3.30.2/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Running CMake to regenerate build system..."
	/opt/homebrew/Cellar/cmake/3.30.2/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/larrybanks/2D_Engine/CMakeFiles /Users/larrybanks/2D_Engine//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/larrybanks/2D_Engine/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named main

# Build rule for target.
main: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 main
.PHONY : main

# fast build rule for target.
main/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/build
.PHONY : main/fast

include/stb_image/stb_image.o: include/stb_image/stb_image.cpp.o
.PHONY : include/stb_image/stb_image.o

# target to build an object file
include/stb_image/stb_image.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/include/stb_image/stb_image.cpp.o
.PHONY : include/stb_image/stb_image.cpp.o

include/stb_image/stb_image.i: include/stb_image/stb_image.cpp.i
.PHONY : include/stb_image/stb_image.i

# target to preprocess a source file
include/stb_image/stb_image.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/include/stb_image/stb_image.cpp.i
.PHONY : include/stb_image/stb_image.cpp.i

include/stb_image/stb_image.s: include/stb_image/stb_image.cpp.s
.PHONY : include/stb_image/stb_image.s

# target to generate assembly for a file
include/stb_image/stb_image.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/include/stb_image/stb_image.cpp.s
.PHONY : include/stb_image/stb_image.cpp.s

src/Camera.o: src/Camera.cpp.o
.PHONY : src/Camera.o

# target to build an object file
src/Camera.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Camera.cpp.o
.PHONY : src/Camera.cpp.o

src/Camera.i: src/Camera.cpp.i
.PHONY : src/Camera.i

# target to preprocess a source file
src/Camera.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Camera.cpp.i
.PHONY : src/Camera.cpp.i

src/Camera.s: src/Camera.cpp.s
.PHONY : src/Camera.s

# target to generate assembly for a file
src/Camera.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Camera.cpp.s
.PHONY : src/Camera.cpp.s

src/Engine.o: src/Engine.cpp.o
.PHONY : src/Engine.o

# target to build an object file
src/Engine.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Engine.cpp.o
.PHONY : src/Engine.cpp.o

src/Engine.i: src/Engine.cpp.i
.PHONY : src/Engine.i

# target to preprocess a source file
src/Engine.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Engine.cpp.i
.PHONY : src/Engine.cpp.i

src/Engine.s: src/Engine.cpp.s
.PHONY : src/Engine.s

# target to generate assembly for a file
src/Engine.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Engine.cpp.s
.PHONY : src/Engine.cpp.s

src/Input/Input.o: src/Input/Input.cpp.o
.PHONY : src/Input/Input.o

# target to build an object file
src/Input/Input.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Input/Input.cpp.o
.PHONY : src/Input/Input.cpp.o

src/Input/Input.i: src/Input/Input.cpp.i
.PHONY : src/Input/Input.i

# target to preprocess a source file
src/Input/Input.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Input/Input.cpp.i
.PHONY : src/Input/Input.cpp.i

src/Input/Input.s: src/Input/Input.cpp.s
.PHONY : src/Input/Input.s

# target to generate assembly for a file
src/Input/Input.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Input/Input.cpp.s
.PHONY : src/Input/Input.cpp.s

src/Renderer/Renderer.o: src/Renderer/Renderer.cpp.o
.PHONY : src/Renderer/Renderer.o

# target to build an object file
src/Renderer/Renderer.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Renderer/Renderer.cpp.o
.PHONY : src/Renderer/Renderer.cpp.o

src/Renderer/Renderer.i: src/Renderer/Renderer.cpp.i
.PHONY : src/Renderer/Renderer.i

# target to preprocess a source file
src/Renderer/Renderer.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Renderer/Renderer.cpp.i
.PHONY : src/Renderer/Renderer.cpp.i

src/Renderer/Renderer.s: src/Renderer/Renderer.cpp.s
.PHONY : src/Renderer/Renderer.s

# target to generate assembly for a file
src/Renderer/Renderer.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Renderer/Renderer.cpp.s
.PHONY : src/Renderer/Renderer.cpp.s

src/Renderer/Shader.o: src/Renderer/Shader.cpp.o
.PHONY : src/Renderer/Shader.o

# target to build an object file
src/Renderer/Shader.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Renderer/Shader.cpp.o
.PHONY : src/Renderer/Shader.cpp.o

src/Renderer/Shader.i: src/Renderer/Shader.cpp.i
.PHONY : src/Renderer/Shader.i

# target to preprocess a source file
src/Renderer/Shader.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Renderer/Shader.cpp.i
.PHONY : src/Renderer/Shader.cpp.i

src/Renderer/Shader.s: src/Renderer/Shader.cpp.s
.PHONY : src/Renderer/Shader.s

# target to generate assembly for a file
src/Renderer/Shader.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Renderer/Shader.cpp.s
.PHONY : src/Renderer/Shader.cpp.s

src/Renderer/Texture.o: src/Renderer/Texture.cpp.o
.PHONY : src/Renderer/Texture.o

# target to build an object file
src/Renderer/Texture.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Renderer/Texture.cpp.o
.PHONY : src/Renderer/Texture.cpp.o

src/Renderer/Texture.i: src/Renderer/Texture.cpp.i
.PHONY : src/Renderer/Texture.i

# target to preprocess a source file
src/Renderer/Texture.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Renderer/Texture.cpp.i
.PHONY : src/Renderer/Texture.cpp.i

src/Renderer/Texture.s: src/Renderer/Texture.cpp.s
.PHONY : src/Renderer/Texture.s

# target to generate assembly for a file
src/Renderer/Texture.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Renderer/Texture.cpp.s
.PHONY : src/Renderer/Texture.cpp.s

src/Renderer/Types/RenderTypes.o: src/Renderer/Types/RenderTypes.cpp.o
.PHONY : src/Renderer/Types/RenderTypes.o

# target to build an object file
src/Renderer/Types/RenderTypes.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Renderer/Types/RenderTypes.cpp.o
.PHONY : src/Renderer/Types/RenderTypes.cpp.o

src/Renderer/Types/RenderTypes.i: src/Renderer/Types/RenderTypes.cpp.i
.PHONY : src/Renderer/Types/RenderTypes.i

# target to preprocess a source file
src/Renderer/Types/RenderTypes.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Renderer/Types/RenderTypes.cpp.i
.PHONY : src/Renderer/Types/RenderTypes.cpp.i

src/Renderer/Types/RenderTypes.s: src/Renderer/Types/RenderTypes.cpp.s
.PHONY : src/Renderer/Types/RenderTypes.s

# target to generate assembly for a file
src/Renderer/Types/RenderTypes.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Renderer/Types/RenderTypes.cpp.s
.PHONY : src/Renderer/Types/RenderTypes.cpp.s

src/Sandbox/Game.o: src/Sandbox/Game.cpp.o
.PHONY : src/Sandbox/Game.o

# target to build an object file
src/Sandbox/Game.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Sandbox/Game.cpp.o
.PHONY : src/Sandbox/Game.cpp.o

src/Sandbox/Game.i: src/Sandbox/Game.cpp.i
.PHONY : src/Sandbox/Game.i

# target to preprocess a source file
src/Sandbox/Game.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Sandbox/Game.cpp.i
.PHONY : src/Sandbox/Game.cpp.i

src/Sandbox/Game.s: src/Sandbox/Game.cpp.s
.PHONY : src/Sandbox/Game.s

# target to generate assembly for a file
src/Sandbox/Game.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Sandbox/Game.cpp.s
.PHONY : src/Sandbox/Game.cpp.s

src/Sandbox/main.o: src/Sandbox/main.cpp.o
.PHONY : src/Sandbox/main.o

# target to build an object file
src/Sandbox/main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Sandbox/main.cpp.o
.PHONY : src/Sandbox/main.cpp.o

src/Sandbox/main.i: src/Sandbox/main.cpp.i
.PHONY : src/Sandbox/main.i

# target to preprocess a source file
src/Sandbox/main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Sandbox/main.cpp.i
.PHONY : src/Sandbox/main.cpp.i

src/Sandbox/main.s: src/Sandbox/main.cpp.s
.PHONY : src/Sandbox/main.s

# target to generate assembly for a file
src/Sandbox/main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Sandbox/main.cpp.s
.PHONY : src/Sandbox/main.cpp.s

src/Scene/Entity.o: src/Scene/Entity.cpp.o
.PHONY : src/Scene/Entity.o

# target to build an object file
src/Scene/Entity.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Scene/Entity.cpp.o
.PHONY : src/Scene/Entity.cpp.o

src/Scene/Entity.i: src/Scene/Entity.cpp.i
.PHONY : src/Scene/Entity.i

# target to preprocess a source file
src/Scene/Entity.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Scene/Entity.cpp.i
.PHONY : src/Scene/Entity.cpp.i

src/Scene/Entity.s: src/Scene/Entity.cpp.s
.PHONY : src/Scene/Entity.s

# target to generate assembly for a file
src/Scene/Entity.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Scene/Entity.cpp.s
.PHONY : src/Scene/Entity.cpp.s

src/Scene/Scene.o: src/Scene/Scene.cpp.o
.PHONY : src/Scene/Scene.o

# target to build an object file
src/Scene/Scene.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Scene/Scene.cpp.o
.PHONY : src/Scene/Scene.cpp.o

src/Scene/Scene.i: src/Scene/Scene.cpp.i
.PHONY : src/Scene/Scene.i

# target to preprocess a source file
src/Scene/Scene.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Scene/Scene.cpp.i
.PHONY : src/Scene/Scene.cpp.i

src/Scene/Scene.s: src/Scene/Scene.cpp.s
.PHONY : src/Scene/Scene.s

# target to generate assembly for a file
src/Scene/Scene.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Scene/Scene.cpp.s
.PHONY : src/Scene/Scene.cpp.s

src/Scene/SceneManager.o: src/Scene/SceneManager.cpp.o
.PHONY : src/Scene/SceneManager.o

# target to build an object file
src/Scene/SceneManager.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Scene/SceneManager.cpp.o
.PHONY : src/Scene/SceneManager.cpp.o

src/Scene/SceneManager.i: src/Scene/SceneManager.cpp.i
.PHONY : src/Scene/SceneManager.i

# target to preprocess a source file
src/Scene/SceneManager.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Scene/SceneManager.cpp.i
.PHONY : src/Scene/SceneManager.cpp.i

src/Scene/SceneManager.s: src/Scene/SceneManager.cpp.s
.PHONY : src/Scene/SceneManager.s

# target to generate assembly for a file
src/Scene/SceneManager.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Scene/SceneManager.cpp.s
.PHONY : src/Scene/SceneManager.cpp.s

src/Window/Window.o: src/Window/Window.cpp.o
.PHONY : src/Window/Window.o

# target to build an object file
src/Window/Window.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Window/Window.cpp.o
.PHONY : src/Window/Window.cpp.o

src/Window/Window.i: src/Window/Window.cpp.i
.PHONY : src/Window/Window.i

# target to preprocess a source file
src/Window/Window.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Window/Window.cpp.i
.PHONY : src/Window/Window.cpp.i

src/Window/Window.s: src/Window/Window.cpp.s
.PHONY : src/Window/Window.s

# target to generate assembly for a file
src/Window/Window.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Window/Window.cpp.s
.PHONY : src/Window/Window.cpp.s

src/glad.o: src/glad.c.o
.PHONY : src/glad.o

# target to build an object file
src/glad.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/glad.c.o
.PHONY : src/glad.c.o

src/glad.i: src/glad.c.i
.PHONY : src/glad.i

# target to preprocess a source file
src/glad.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/glad.c.i
.PHONY : src/glad.c.i

src/glad.s: src/glad.c.s
.PHONY : src/glad.s

# target to generate assembly for a file
src/glad.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/glad.c.s
.PHONY : src/glad.c.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... main"
	@echo "... include/stb_image/stb_image.o"
	@echo "... include/stb_image/stb_image.i"
	@echo "... include/stb_image/stb_image.s"
	@echo "... src/Camera.o"
	@echo "... src/Camera.i"
	@echo "... src/Camera.s"
	@echo "... src/Engine.o"
	@echo "... src/Engine.i"
	@echo "... src/Engine.s"
	@echo "... src/Input/Input.o"
	@echo "... src/Input/Input.i"
	@echo "... src/Input/Input.s"
	@echo "... src/Renderer/Renderer.o"
	@echo "... src/Renderer/Renderer.i"
	@echo "... src/Renderer/Renderer.s"
	@echo "... src/Renderer/Shader.o"
	@echo "... src/Renderer/Shader.i"
	@echo "... src/Renderer/Shader.s"
	@echo "... src/Renderer/Texture.o"
	@echo "... src/Renderer/Texture.i"
	@echo "... src/Renderer/Texture.s"
	@echo "... src/Renderer/Types/RenderTypes.o"
	@echo "... src/Renderer/Types/RenderTypes.i"
	@echo "... src/Renderer/Types/RenderTypes.s"
	@echo "... src/Sandbox/Game.o"
	@echo "... src/Sandbox/Game.i"
	@echo "... src/Sandbox/Game.s"
	@echo "... src/Sandbox/main.o"
	@echo "... src/Sandbox/main.i"
	@echo "... src/Sandbox/main.s"
	@echo "... src/Scene/Entity.o"
	@echo "... src/Scene/Entity.i"
	@echo "... src/Scene/Entity.s"
	@echo "... src/Scene/Scene.o"
	@echo "... src/Scene/Scene.i"
	@echo "... src/Scene/Scene.s"
	@echo "... src/Scene/SceneManager.o"
	@echo "... src/Scene/SceneManager.i"
	@echo "... src/Scene/SceneManager.s"
	@echo "... src/Window/Window.o"
	@echo "... src/Window/Window.i"
	@echo "... src/Window/Window.s"
	@echo "... src/glad.o"
	@echo "... src/glad.i"
	@echo "... src/glad.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

