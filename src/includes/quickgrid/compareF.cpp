#include "compareF.h"

bool CompareF::operator() (const Node* a, const Node* b) const {
	return (a->getF() > b->getF());
}
