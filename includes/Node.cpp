#include "Node.h"


Node::Node(int i, int j, char c) :	row(i), 
					col(j), 
					symbol(c), 
					h(FLOAT_MAX), 
					g(FLOAT_MAX), 
					f(FLOAT_MAX), 
					parent(nullptr) {}


void Node::setSymbol(char c) { symbol = c; }

int  Node::getRow()    { return row;    }
int  Node::getCol()    { return col;    }
char Node::getSymbol() { return symbol; }

void Node::setH(float val) { h = val; }
void Node::setG(float val) { g = val; }
void Node::setF(float val) { f = val; }

float Node::getH() const { return h; }
float Node::getG() const { return g; }
float Node::getF() const { return f; }

void Node::addNeighbor(std::pair<int, int> coord)          { neighbors.push_back(coord); }
std::vector<std::pair<int, int>> Node::getNeighborCoords() { return neighbors;           }

void Node::setParent(Node*& sq) { parent = sq;   }
Node* Node::getParent()        { return parent; }

bool Node::isObstacle() { return (symbol == 'X'); }

void Node::discovered() { symbol = DISCOVERED; }
void Node::evaluated()  { symbol = EVALUATED;  }
void Node::path()       { symbol = PATH;       }


