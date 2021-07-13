#ifndef __DFS_PATHFINDER_H__
#define __DFS_PATHFINDER_H__

#include <limits>
#include <vector>
#include <queue>
#include <unordered_set>
#include "pathfinder.h"

class DFS : public Pathfinder {
private:
  int recurse(Canvas*& canvas, Node*& current, Node*& start, Node*& end, std::unordered_set<Node*>& visited);

public:
  DFS();
  bool run(Canvas* canvas);
};

#endif
