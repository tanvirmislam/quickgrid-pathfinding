#include "compareG.h"

bool CompareG::operator() (const Node* a, const Node* b) const {
	return (a->getG() > b->getG());
}
