#include "Canvas.h"


Canvas::Canvas(std::string filename) { 
	readGrid(filename);
	
	rows = grid.size();
	cols = (!grid.empty() ? grid[0].size() : 0);
	
	assignNeighbors();
}

Canvas::~Canvas() {
	if (!grid.empty()) {
		for (int i = 0; i < rows; i++) {
			if (!grid[i].empty()) {
				for (int j = 0; j < cols; j++) {
					delete grid[i][j];
				}
			}
		}
	}
}

void Canvas::readGrid(std::string filename) {
	std::ifstream fin(filename);
	
	int i = 0, j = 0;
	char c;
	std::vector<Node*> line;
		
	while (!fin.eof()) {
		fin.get(c);
		if (c == '\n') {
			if (j > 0) {
				grid.push_back(line);
			}
			line.clear();
			i++;
			j = 0;
		}
		else {
			Node* sq = new Node(i, j, c);
			line.push_back(sq);
			if (c == 'S') {
				start = std::make_pair(i, j);
			}
			else if (c == 'E') {
				end = std::make_pair(i, j);
			}
			j++;
		}
	}
}

void Canvas::assignNeighbors() {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			Node* sq = grid[i][j];

			if (i > 0) {
				if (!(grid[i-1][j])->isObstacle()) {
					sq->addNeighbor(std::make_pair(i-1, j));
				}
			}
			if (i < rows-1) {
				if (!(grid[i+1][j])->isObstacle()) {
					sq->addNeighbor(std::make_pair(i+1, j));
				}
			}
			if (j > 0) {
				if (!(grid[i][j-1])->isObstacle()) {
					sq->addNeighbor(std::make_pair(i, j-1));
				}
			}		
			if (j < cols-1) {
				if (!(grid[i][j+1])->isObstacle()) {
					sq->addNeighbor(std::make_pair(i, j+1));
				}
			}		
		}
	}
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
	for (auto& v : grid) {
		for (Node* sq : v) {
			std::cout << sq->getSymbol();
		}
		std::cout << std::endl;
	}
	std::cout << std::flush;	
	usleep(nanosec);
}


