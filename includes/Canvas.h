#ifndef __CANVAS_H__
#define __CANVAS_H__

#include "Node.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <utility>
#include <math.h>
#include <unistd.h>

#define DEFAULT_INTERVAL 15000

class Canvas {
private:
	std::vector<std::vector<Node*>> grid;
	 
	int rows;
	int cols;
	
	std::pair<int, int> start;
	std::pair<int, int> end;

	void readGrid(std::string filename);
	void assignNeighbors();

public:
	Canvas(std::string filename); 	
	~Canvas();

	Node* getStart();
	Node* getEnd();
	Node* get(int i, int j);
	Node* get(std::pair<int, int> coord);

	float getDist(Node* a, Node* b);

	void draw();
	void draw(int nanosec);
};

#endif
