#include "elephant.h"
#include <iostream>

using namespace std;

Elephant::Elephant(Color color, int y, int x) : Piece(color, y, x) {
    setName(PIECE_NAME[ELEPHANT - 1]);
    setRank(ELEPHANT);
}

bool Elephant::isMoveValid(Board* board, int y, int x) {
    if (abs(getY() - y) + abs(getX() - x) != 1)  // move other than 1 square
        return false;
    return Piece::isMoveValid(board, y, x);
}
