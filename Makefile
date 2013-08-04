CXX = g++
CXXFLAGS = -Wall -MMD -std=c++11
OBJECTS = grid.o block.o main.o o.o scoreboard.o level0.o level1.o level2.o level3.o level.o
EXEC = quadris
DEPENDS = ${OBJECTS:.o=.d}

${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -L/usr/X11R6/lib -lX11 -o ${EXEC}

-include ${DEPENDS}

.PHONY : clean

clean :
	rm ${OBJECTS} ${EXEC} ${DEPENDS}