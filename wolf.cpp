#include "wolf.h"
#include <iostream>

using namespace std;

Wolf::Wolf(Color color, int y, int x) : Piece(color, y, x) {
    setName(PIECE_NAME[WOLF - 1]);
    setRank(WOLF);
}

bool Wolf::isMoveValid(Board* board, int y, int x) {
    if (abs(getY() - y) + abs(getX() - x) != 1)  // move other than 1 square
        return false;
    return Piece::isMoveValid(board, y, x);
}
