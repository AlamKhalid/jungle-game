#include "cat.h"
#include <iostream>

using namespace std;

Cat::Cat(Color color, int y, int x) : Piece(color, y, x) {
    setName(PIECE_NAME[CAT-1]);
    setRank(CAT);
}

bool Cat::isMoveValid(Board* board, int y, int x) {
    if (abs(getY() - y) + abs(getX() - x) != 1)  // move other than 1 square
        return false;
    return Piece::isMoveValid(board, y, x);
}
