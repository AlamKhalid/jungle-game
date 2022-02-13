#ifndef HUMAN_H
#define HUMAN_H

#include "player.h"

class Human : public Player
{
public:
    Human(string name, Color color);
    virtual void makeMove(Board* board);
};

#endif /* HUMAN_H */
