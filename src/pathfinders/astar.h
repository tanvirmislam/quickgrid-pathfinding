#ifndef __ASTAR_PATHFINDER_H__
#define __ASTAR_PATHFINDER_H__

#include <vector>
#include <limits>
#include <unordered_set>
#include "pathfinder.h"

class AStar : public Pathfinder {
private:
  Node* getMin(std::unordered_set<Node*>& nodeSet);

public:
  AStar();
  bool run(Canvas* canvas);
};

#endif
