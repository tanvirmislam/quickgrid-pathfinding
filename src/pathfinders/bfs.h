#ifndef __BFS_PATHFINDER_H__
#define __BFS_PATHFINDER_H__

#include <limits>
#include <vector>
#include <queue>
#include <unordered_set>
#include "pathfinder.h"

class BFS : public Pathfinder {
public:
  BFS();
  bool run(Canvas* canvas);
};

#endif
