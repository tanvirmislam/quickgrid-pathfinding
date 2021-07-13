#ifndef __DIJKSTRA_PATHFINDER_H__
#define __DIJKSTRA_PATHFINDER_H__

#include <limits>
#include <vector>
#include <queue>
#include <unordered_set>
#include "pathfinder.h"

class Dijkstra : public Pathfinder {
public:
  Dijkstra();
  bool run(Canvas* canvas);
};

#endif
