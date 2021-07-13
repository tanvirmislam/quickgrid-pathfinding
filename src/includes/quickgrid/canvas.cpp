#include "canvas.h"


Canvas::Canvas(std::string filepath) { 
	// Read the file to store grid information
	readGrid(filepath);
	
	// Set number of rows and columns
	rows = grid.size();
	cols = (!grid.empty() ? grid[0].size() : 0);
	
	// Assign neighbors to each grid node
	assignNeighbors();
}

Canvas::~Canvas() {
	// Delete the grid nodes
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			delete grid[i][j];
		}
	}
}

void Canvas::readGrid(std::string filepath) {
	// Read the file to retrieve grid information
	std::ifstream fin(filepath);
	
	int i = 0;
	int j = 0;
	char c;

	std::vector<Node*> line;

	while (!fin.eof()) {
		// Get a character
		fin.get(c);

		if (c == '\n') {
			// Reached the end of a line
			if (j > 0) {
				grid.push_back(line);
			}

			line.clear();
			i++;
			j = 0;
		}
		else {
			// Continue reading the current line
			Node* node = new Node(i, j, c);
			line.push_back(node);

			if (c == Symbols::START) {
				start = std::make_pair(i, j);
			}
			else if (c == Symbols::END) {
				end = std::make_pair(i, j);
			}

			j++;
		}
	}
}

void Canvas::assignNeighbors() {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			Node* node = grid[i][j];

			if (i > 0) {
				if (!(grid[i-1][j])->isObstacle()) {
					node->addNeighbor(std::make_pair(i-1, j));
				}
			}

			if (i < rows-1) {
				if (!(grid[i+1][j])->isObstacle()) {
					node->addNeighbor(std::make_pair(i+1, j));
				}
			}

			if (j > 0) {
				if (!(grid[i][j-1])->isObstacle()) {
					node->addNeighbor(std::make_pair(i, j-1));
				}
			}

			if (j < cols-1) {
				if (!(grid[i][j+1])->isObstacle()) {
					node->addNeighbor(std::make_pair(i, j+1));
				}
			}		
		}
	}
}

bool Canvas::isEmpty() {
	return grid.empty() || grid[0].empty();
}

Node* Canvas::get(int i, int j) {
	if (i >= 0 && i < rows && j >= 0 && j < cols) {
		return grid[i][j];
	}
	else {
		return nullptr;
	}
}

Node* Canvas::get(std::pair<int, int> coord) {
	return Canvas::get(coord.first, coord.second);
}

Node* Canvas::getStart() {
	return Canvas::get(start); 
}

Node* Canvas::getEnd() {
	return Canvas::get(end);
}

float Canvas::getDist(Node* a, Node* b) {
	float distX = (float) (a->getCol() - b->getCol());
	float distY = (float) (a->getRow() - b->getRow());
	return (float) (sqrt((distX*distX) + (distY*distY)));
}

void Canvas::draw() {
	Canvas::draw(DEFAULT_INTERVAL);
}

void Canvas::draw(int nanosec) {
	system("clear");

	for (auto& row : grid) {
		for (auto& node : row) {
			std::cout << node->getSymbol();
		}
		std::cout << std::endl;
	}

	std::cout << std::flush;	
	usleep(nanosec);
}
