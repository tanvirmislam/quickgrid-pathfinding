#ifndef __PATHFINDER_H__
#define __PATHFINDER_H__

#include "quickgrid.h"

class Pathfinder {
public:
  Pathfinder();
  virtual ~Pathfinder() = 0;
  virtual bool run(Canvas* canvas) = 0;
};

#endif
