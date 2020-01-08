SRC_DIR := src
OBJ_DIR := build/obj
SRC_FILES := ${wildcard ${SRC_DIR}/*.cpp}
OBJ_FILES := ${patsubst ${SRC_DIR}/%.cpp, ${OBJ_DIR}/%.o, ${SRC_FILES} }

CC := g++

CPPFLAGS := -c -Wall
SFML := -IC:/SFML-2.5.1/include -LC:/SFML-2.5.1/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network -lopengl32

all: clean sfml.exe

sfml.exe : ${OBJ_FILES}
	${CC} -g -o build/$@ $^ ${SFML}

${OBJ_DIR}/%.o : ${SRC_DIR}/%.cpp
	${CC} ${CPPFLAGS} -c -o $@ $< ${SFML}



# sfml: build/obj/main.o build/obj/Game.o
# 	${CC} -g -o build/Game.exe build/obj/main.o build/obj/Game.o  ${SFML}

# main.o: src/main.cpp
# 	${CC} ${CPPFLAGS} src/main.cpp -o build/obj/main.o ${SFML}

# Game.o: src/Game.cpp
# 	${CC} ${CPPFLAGS} src/Game.cpp -o build/obj/Game.o ${SFML}


# clean:
# 	del ${OBJ_DIR}/*.o
clean:
	del /s *.o