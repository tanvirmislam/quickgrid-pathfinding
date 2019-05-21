#ifndef __COMPARATOR_H__
#define __COMPARATOR_H__

#include "Node.h"

class CompareF {
public:
	bool operator() (const Node* a, const Node* b) const;
};

#endif
