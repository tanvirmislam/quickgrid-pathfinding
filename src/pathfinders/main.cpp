#include <iostream>
#include <string>
#include <vector>
#include "pathfinder.h"
#include "astar.h"
#include "dijkstra.h"
#include "bfs.h"
#include "dfs.h"

int main(int argc, char* argv[]) {
	if (argc != 3) {
		std::cout << "usage: ./run <pathfinding algorithm name> <grid file name>" << std::endl;
		std::cout << "example: ./run astar grid-1.txt" << std::endl;
		exit(1);
	}

  std::string pathfindingAlgorithm = argv[1];
  std::string gridFilePath = "../grids/" + std::string(argv[2]);

	Canvas* canvas = new Canvas(gridFilePath);
  Pathfinder* pathfinder;

  if (pathfindingAlgorithm == "astar") {
    pathfinder = new AStar();
  }
	else if (pathfindingAlgorithm == "dijkstra") {
		pathfinder = new Dijkstra();
	}
	else if (pathfindingAlgorithm == "bfs") {
		pathfinder = new BFS();
	}
	else if (pathfindingAlgorithm == "dfs") {
		pathfinder = new DFS();
	}
	else {
		std::cout << "Unknown pathfinding algorithm" << std::endl;
		exit(1);
	}

	pathfinder->run(canvas);
	canvas->draw(0);

  delete pathfinder;
  delete canvas;

	return 0;  
}
