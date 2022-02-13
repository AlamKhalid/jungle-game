#ifndef CAT_H
#define CAT_H

#include "piece.h"

class Cat : public Piece
{
public:
    Cat(Color color, int y, int x);
    virtual bool isMoveValid(Board* board, int y, int x);
};

#endif /* CAT_H */
