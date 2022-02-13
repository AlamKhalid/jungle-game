#ifndef MACHINE_H
#define MACHINE_H

#include "player.h"

class Machine : public Player
{
public:
    Machine(string name, Color color);
    virtual void makeMove(Board* board);
    // ... more functions or data members if needed
};

#endif /* MACHINE_H */
