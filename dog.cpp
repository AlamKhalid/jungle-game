#include "dog.h"
#include <iostream>

using namespace std;

Dog::Dog(Color color, int y, int x) : Piece(color, y, x) {
    setName(PIECE_NAME[DOG-1]);
    setRank(DOG);
}

bool Dog::isMoveValid(Board* board, int y, int x) {
    if (abs(getY() - y) + abs(getX() - x) != 1)  // move other than 1 square
        return false;
    return Piece::isMoveValid(board, y, x);
}
