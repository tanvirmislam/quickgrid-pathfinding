#include "node.h"

Node::Node(int i, int j, char c)
	:	row(i),
		col(j),
		symbol(c),
		h(FLOAT_MAX),
		g(FLOAT_MAX),
		f(FLOAT_MAX),
		parent(nullptr) {}

void Node::setSymbol(char c) {
	symbol = c;
}

int Node::getRow() const {
	return row;
}

int Node::getCol() const {
	return col;
}

char Node::getSymbol() const {
	return symbol;
}

void Node::setH(float val) {
	h = val;
}

void Node::setG(float val) {
	g = val;
}

void Node::setF(float val) {
	f = val;
}

float Node::getH() const {
	return h;
}

float Node::getG() const {
	return g;
}

float Node::getF() const {
	return f;
}

void Node::addNeighbor(std::pair<int, int> coord) {
	neighbors.push_back(coord);
}

std::vector<std::pair<int, int>> Node::getNeighborCoords() const {
	return neighbors;
}

void Node::setParent(Node*& sq) {
	parent = sq;
}

Node* Node::getParent() const {
	return parent;
}

bool Node::isObstacle() const {
	return (symbol == Symbols::OBSTACLE);
}

void Node::setAsDiscovered() {
	symbol = Symbols::DISCOVERED;
}

void Node::setAsEvaluated() {
	symbol = Symbols::EVALUATED;
}

void Node::setAsPath() {
	symbol = Symbols::PATH;
}

