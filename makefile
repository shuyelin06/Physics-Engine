# Main MakeFile for the Physics Engine
# Compiler
CC := g++
# Compiler Flags (-Wall: Show all warnings, -g: Debugging Features)
CFLAGS := -Wall -g

# Working Directory
WORKING_DIRECTORY := $(shell pwd)

# Include Directory
INCLUDE := $(WORKING_DIRECTORY)\include
# Library Paths
LIB_PATH := -L"$(WORKING_DIRECTORY)\libs\SFML-2.5.1"
# Library Files
LIB_FILES := -lsfml-main -lsfml-graphics -lsfml-window -lsfml-system

# Folders
SRC := ./src
OBJ := ./bin/obj
EXE := ./bin/exe

# Compile Command for Convenience
define compile-command
$(CC) $(CFLAGS) -I"$(INCLUDE)" -c $(<) -o $(@) 
endef

# Object Files
Objects = $(OBJ)/Main.o $(OBJ)/Simulator.o $(OBJ)/Polygon.o $(OBJ)/Vector.o $(OBJ)/PhysicsObject.o $(OBJ)/Renderer.o

# Main Executable
$(BIN)/Main.exe: $(Objects)
	$(CC) $(CFLAGS) $(LIB_PATH) -o $(EXE)/Main.exe $(Objects) $(LIB_FILES)

# Implicit Rule for Core Folder
$(OBJ)/%.o: $(SRC)/core/%.cpp
	$(compile-command)

# Implicit Rule for Geometry Folder
$(OBJ)/%.o: $(SRC)/geometry/%.cpp
	$(compile-command)

# Implicit Rule for Physics Folder
$(OBJ)/%.o: $(SRC)/physics/%.cpp
	$(compile-command)

# Implicit Rule for Rendering Folder
$(OBJ)/%.o: $(SRC)/rendering/%.cpp
	$(compile-command)

# Phony Commands
.PHONY: clean run
clean:
	rm $(OBJ)/*.o
	rm $(EXE)/Main.exe
run:
	$(EXE)/Main.exe
