#ifndef JUMPER_H
#define JUMPER_H

#include "piece.h"

class Jumper
{
public:
	Jumper();
	bool isJumpable(Board* board, Piece* p, int y, int x, int steps);
};

#endif  /* JUMPER_H */
