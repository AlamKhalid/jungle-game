#ifndef TIGER_H
#define TIGER_H

#include "piece.h"
#include "jumper.h"

// Tiger class is a subclass of both Piece and Jumper (multiple inheritance) 
class Tiger : public Piece, public Jumper
{
public:
    Tiger(Color color, int y, int x);
    virtual bool isMoveValid(Board* board, int y, int x);
};

#endif /* TIGER_H */
