#ifndef DOG_H
#define DOG_H

#include "piece.h"

class Dog : public Piece
{
public:
    Dog(Color color, int y, int x);
    virtual bool isMoveValid(Board* board, int y, int x);
};

#endif /* DOG_H */
