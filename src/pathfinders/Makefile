CC = g++
CC_STD_VERSION = -std=c++14
INCLUDES = ../includes/quickgrid/node.cpp ../includes/quickgrid/compareG.cpp ../includes/quickgrid/compareF.cpp ../includes/quickgrid/canvas.cpp

MAIN_FILE = main.cpp
MAIN_OUTPUT = run

PATHFINDER_SOURCE = pathfinder.cpp

ASTAR_SOURCE = astar.cpp
DIJKSTRA_SOURCE = dijkstra.cpp
BFS_SOURCE = bfs.cpp

COMPILABLES = $(INCLUDES) $(MAIN_FILE) $(PATHFINDER_SOURCE) $(ASTAR_SOURCE) $(DIJKSTRA_SOURCE) $(BFS_SOURCE)

all: $(COMPILABLES)
	$(CC) $(COMPILABLES) -o $(MAIN_OUTPUT) $(CC_STD_VERSION)

clean:
	rm -rf $(MAIN_OUTPUT) *.o *.exe *.dSYM
