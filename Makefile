SRC_DIR := src
OBJ_DIR := build/obj
SRC_FILES := ${wildcard ${SRC_DIR}/*.cpp}
OBJ_FILES := ${patsubst ${SRC_DIR}/%.cpp, ${OBJ_DIR}/%.o, ${SRC_FILES} }

CC := g++

CPPFLAGS := -c -Wall
SFML := -IC:/SFML-2.5.1/include -LC:/SFML-2.5.1/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network -lopengl32
WSL_SFML := -I/mnt/c/SFML-2.5.1/include -L/mnt/c/SFML-2.5.1/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network -lopengl32

# Default
all: clean sfml.exe

# Compiles the code
sfml.exe : ${OBJ_FILES}
	${CC} -g -o build/$@ $^ ${SFML}

${OBJ_DIR}/%.o : ${SRC_DIR}/%.cpp
	${CC} ${CPPFLAGS} -c -o $@ $< ${SFML}

# Deletes all the previously compiled objects - ONLY WORKS WHEN USING IT ON POWERSHELL & CMD
# TODO see if possible to only delete those that have changes made
clean:
	del /s *.o

# Creates the folder structure
create:
