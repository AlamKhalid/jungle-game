#include "jumper.h"
#include <iostream>
#include <algorithm>

using namespace std;

Jumper::Jumper() {
}

/* Check if animal p can jump over a river
   The 'steps' argument is used to control how many river cells to test.
   Call isJumpable(board, p, y, x, 2) to test if p can do a horizontal river jump (2 steps)
   Call isJumpable(board, p, y, x, 3) to test if p can do a vertical river jump (3 steps)
   Return true if p can jump and false otherwise (e.g. due to blocking by a Rat in river)
 */
bool Jumper::isJumpable(Board* board, Piece* p, int y, int x, int steps) {
    /* TODO: Add code to check if p can jump over 'steps' river squares 
             to the destination(y, x) */
    Piece* o;
    int curr_y = p->getY(), curr_x = p->getX();
    int change;
    // for horizontal jump
    if (steps == 2) {
        change = x > curr_x ? 1 : -1;
        for (int i = 1; i <= steps; i++) {
            int new_y = curr_y, new_x = curr_x + (i * change);
            o = board->get(new_y, new_x);
            if (board->isRiver(new_y, new_x) && o == EMPTY) {
                // true condition
            }
            else if (o != EMPTY && o->getColor() == p->getColor()) {
                // true condition
            }
            else {
                return false;
            }
        }
        o = board->get(curr_y, curr_x + (steps + 1)*change);
        if (p->isOpponent(o) && !p->canCapture(o))
            return false;
    }
    else {
        change = y > curr_y ? 1 : -1;
        for (int i = 1; i <= steps; i++) {
            int new_y = curr_y + (i * change), new_x = curr_x;
            
            o = board->get(new_y, new_x);
            if (board->isRiver(new_y, new_x) && o == EMPTY) {
                // true condition
                
            }
            else if (o->getColor() == p->getColor()) {
                // true condition
            }
            else {
                return false;
            }
        }
        o = board->get(curr_y + (steps + 1) * change, curr_x );
        if (p->isOpponent(o) && !p->canCapture(o))
            return false;
    }
    return true;
}