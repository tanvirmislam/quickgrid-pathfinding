#ifndef __QUICKGRID_CANVAS_NODE_H__
#define __QUICKGRID_CANVAS_NODE_H__

#include <vector>
#include <utility>
#include <limits>
#include "symbols.h"

#define FLOAT_MAX std::numeric_limits<float>::max()

class Node {
private:
	int row;
	int col;
	char symbol;

	float h;
	float g;
	float f;

	std::vector<std::pair<int, int>> neighbors;

	Node* parent;

public:
	Node(int i, int j, char c);

	void setSymbol(char c);

	int getRow() const;
	int getCol() const;
	char getSymbol() const;

	void setH(float val);
	void setG(float val);
	void setF(float val);

	float getH() const;
	float getG() const;
	float getF() const;

	void addNeighbor(std::pair<int, int> coord);
	std::vector<std::pair<int, int>> getNeighborCoords() const;

	void setParent(Node*& node);
	Node* getParent() const;

	bool isObstacle() const;

	void setAsDiscovered();
	void setAsEvaluated();
	void setAsPath();
};

#endif
