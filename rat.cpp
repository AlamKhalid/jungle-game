#include "rat.h"
#include <iostream>

using namespace std;

Rat::Rat(Color color, int y, int x) : Piece(color, y, x) {
    setName(PIECE_NAME[RAT-1]);
    setRank(RAT);
}

bool Rat::isMoveValid(Board* board, int y, int x) {
    // TODO: Override the superclass version of valid move checks
    // e.g., to allow a Rat to move into a square occuppied by an Elephant 
    //       to allow a Rat to enter a water square
    if (abs(getY() - y) + abs(getX() - x) != 1)  // move other than 1 square
        return false;
    Piece* q = board->get(y, x);  // target cell
    if (isOpponent(q) && !canCapture(q))  // cell occupied by higher-rank opponent
        return false;
    return true;
}

bool Rat::canCapture(Piece* p) {
    // TODO: Override the superclass version of capture checks
    // A Rat can capture an Elephant
    if (p != EMPTY && isOpponent(p) && !this->isTrapped()) {
        int r = p->getRank();
        if (r == 1 || r == 8 || p->isTrapped()) return true;
    }
    return false;
}