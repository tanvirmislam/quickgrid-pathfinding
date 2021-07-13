#ifndef __F_VALUE_COMPARATOR_H__
#define __F_VALUE_COMPARATOR_H__

#include "node.h"

class CompareF {
public:
	bool operator() (const Node* a, const Node* b) const;
};

#endif
