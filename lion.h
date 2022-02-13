#ifndef LION_H
#define LION_H

#include "piece.h"
#include "jumper.h"

// Lion class is a subclass of both Piece and Jumper (multiple inheritance) 
class Lion : public Piece, public Jumper
{
public:
    Lion(Color color, int y, int x);
    virtual bool isMoveValid(Board* board, int y, int x);
};

#endif /* LION_H */
