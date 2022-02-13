#include "lion.h"
#include <iostream>

using namespace std;

Lion::Lion(Color color, int y, int x) : Piece(color, y, x) {
    setName(PIECE_NAME[LION - 1]);
    setRank(LION);
}

bool Lion::isMoveValid(Board* board, int y, int x) {
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
