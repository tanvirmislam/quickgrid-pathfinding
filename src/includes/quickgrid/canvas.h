#ifndef __QUICKGRID_CANVAS_H__
#define __QUICKGRID_CANVAS_H__

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <utility>
#include <math.h>
#include <unistd.h>
#include <term.h>
#include "node.h"
#include "symbols.h"

#define DEFAULT_INTERVAL 40000

class Canvas {
private:
	std::vector<std::vector<Node*>> grid;

	int rows;
	int cols;

	std::pair<int, int> start;
	std::pair<int, int> end;

	void readGrid(std::string filepath);
	void assignNeighbors();

public:
	Canvas(std::string filepath); 	
	~Canvas();

	bool isEmpty();

	Node* getStart();
	Node* getEnd();
	Node* get(int i, int j);
	Node* get(std::pair<int, int> coord);

	float getDist(Node* a, Node* b);

	void draw();
	void draw(int nanosec);
};

#endif
