#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "player.h"

enum Mode { H2H = 1, H2M, M2M };

enum State { RUNNING, GAME_OVER };

class Game
{
private:
    Board* board;       // the game board
    Player* players[2]; // the two players
    Color turn;         // color of the current player
    State state;        // running or game over
public:
    Game(Mode mode, char* filename);
    void run();
    Player* getPlayer(Color color) const;
    Color getTurn() const;
    void setTurn(Color turn);
    State getState() const;
    void setState(State state);
};

#endif /* GAME_H */
