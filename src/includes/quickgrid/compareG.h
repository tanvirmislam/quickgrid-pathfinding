#ifndef __G_VALUE_COMPARATOR_H__
#define __G_VALUE_COMPARATOR_H__

#include "node.h"

class CompareG {
public:
	bool operator() (const Node* a, const Node* b) const;
};

#endif
