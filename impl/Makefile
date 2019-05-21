INCLUDES = ../includes/Node.cpp ../includes/CompareG.cpp ../includes/CompareF.cpp ../includes/Canvas.cpp
ASTAR = astar.cpp
DIJKSTRA = dijkstra.cpp
BFS = bfs.cpp
DFS = dfs.cpp

all: $(INCLUDES) $(ASTAR) $(DIJKSTRA)
	g++ $(ASTAR) $(INCLUDES) -o runastar -std=c++14
	g++ $(DIJKSTRA) $(INCLUDES) -o rundijkstra -std=c++14
	g++ $(BFS) $(INCLUDES) -o runbfs -std=c++14
	g++ $(DFS) $(INCLUDES) -o rundfs -std=c++14
clean:
	rm -f -r runastar rundijkstra runbfs rundfs *.o *.dSYM
