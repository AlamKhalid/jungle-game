#ifndef RAT_H
#define RAT_H

#include "piece.h"

class Rat : public Piece
{
public:
    Rat(Color color, int y, int x);
    virtual bool isMoveValid(Board* board, int y, int x);
    virtual bool canCapture(Piece* p);
};

#endif /* RAT_H */
