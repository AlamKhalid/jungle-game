#ifndef WOLF_H
#define WOLF_H

#include "piece.h"

class Wolf : public Piece
{
public:
    Wolf(Color color, int y, int x);
    virtual bool isMoveValid(Board* board, int y, int x);
};

#endif /* WOLF_H */
