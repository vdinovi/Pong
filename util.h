#ifndef UTIL_H
#define UTIL_H

#include <SFML/Graphics.hpp>
#include <cstdlib>

#define max(a,b) \
({ __typeof__ (a) _a = (a); \
__typeof__ (b) _b = (b); \
_a > _b ? _a : _b; })

#define min(a,b) \
({ __typeof__ (a) _a = (a); \
__typeof__ (b) _b = (b); \
_a < _b ? _a : _b; })

#define FRAME_SIZE_X 1200
#define FRAME_SIZE_Y 800

#define MAX_VELOCITY 10
#define MAX_ACCEL 5

#endif