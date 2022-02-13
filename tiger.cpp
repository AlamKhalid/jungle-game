#include "tiger.h"
#include <iostream>

using namespace std;

Tiger::Tiger(Color color, int y, int x) : Piece(color, y, x) {
    setName(PIECE_NAME[TIGER-1]);
    setRank(TIGER);
}

bool Tiger::isMoveValid(Board* board, int y, int x) {
    /* TODO: implement valid move check specific to a Tiger
       Hint: make use of the isJumpable() function inherited from Jumper
             to check if horizontal and vertical jump can be done */
    if (abs(getY() - y) + abs(getX() - x) == 1) {
        return Piece::isMoveValid(board, y, x);
    }
    else {
        if (getY() == y) {
            return isJumpable(board, this, y, x, 2);
        }
        else {
            return isJumpable(board, this, y, x, 3);
        }
    }
}
