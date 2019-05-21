#ifndef __SQUARE_H__
#define __SQUARE_H__

#include <vector>
#include <utility>
#include <limits>

#define DISCOVERED '+'
#define EVALUATED  '='
#define PATH       '*'

#define FLOAT_MAX std::numeric_limits<float>::max()

class Node {
private:
	int  row;
	int  col;
	char symbol;

	float h;
	float g;
	float f;

	std::vector<std::pair<int, int>> neighbors;

	Node* parent;

public:
	Node(int i, int j, char c);

	void setSymbol(char c);

	int  getRow();
	int  getCol();
	char getSymbol();

	void setH(float val);
	void setG(float val);
	void setF(float val);

       	float getH() const;
	float getG() const;
	float getF() const;

	void addNeighbor(std::pair<int, int> coord);
	std::vector<std::pair<int, int>> getNeighborCoords();

	void setParent(Node*& sq);
	Node* getParent();

	bool isObstacle();

	void discovered();
	void evaluated();
	void path();
};

#endif
