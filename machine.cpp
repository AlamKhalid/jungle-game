#include <iostream>
#include<ctime>
#include "machine.h"
#include "game.h"
#include "board.h"

using namespace std;

Machine::Machine(string name, Color color) : Player(name, color) {
    // TODO: randomize the seed of random number generator 
    //       using the current time
    srand(time(NULL));
}

// a sample machine that makes random valid moves
void Machine::makeMove(Board* board) {
    // TODO: make a random but valid move of a randomly picked piece on a board
    // Hint: there exist many ways to do so, one way is as follows:
    // - generate a random integer for picking a piece r from the player's pieces vector
    // - set y1, x1 to r->getY(), r->getX()
    // - generate random integers y2 and x2 in range of [0, H) and [0, W) respectively
    //   [or better in the y, x range of the 4 neighboring cells around (y1, x1), note to
    //    handle jumpable cells, 2 or 3 cells away, as well for Tiger and Lion]
    // - call board's move(y1, x1, y2, x2)
    // - once a valid move is returned, print the from and to cell addresses 
    //   and exit this function
    // Note: it can happen that no valid move can be found despite repeated picks.
    //       For example, only a Rat remains alive at a corner of the board while 
    //       the two cells it may go have been occupied by a Cat and a Dog.
    //       In this case, the player must surrender (set the opponent as winner).
    int moves[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
    int jumpMoves[4][2] = { { 4,0 },{-4,0},{0,3},{0,-3} };
    int size = getPieceCount();
    cout << this->getName() << "'s turn: ";
    for (int k = 0; k < 10; k++) {
        int random_idx = rand() % size;
        Piece* p = getPiece(random_idx);
        int y1 = p->getY(), x1 = p->getX(), y2, x2;
        string name = p->getName();
        // if either lion of tiger
        if (name == PIECE_NAME[LION - 1] || name == PIECE_NAME[TIGER - 1]) {
            // try jump
            int tryJump = rand() % 10 + 1;
            if (tryJump > 5) {  // also try jump randomly
                for (int i = 0; i < 4; i++) {
                    y2 = y1 + jumpMoves[i][0];
                    x2 = x1 + jumpMoves[i][1];
                    bool valid = board->move(y1, x1, y2, x2);
                    if (valid) {
                        cout << "From: " << char('a' + x1) << y1 + 1 << ", To: " << char('a' + x2) << y2 + 1 << endl;
                        return;
                    }
                }
            }
        }
        for (int i = 0; i < 4; i++) {
            y2 = y1 + moves[i][0];
            x2 = x1 + moves[i][1];
            bool valid = board->move(y1, x1, y2, x2);
            if (valid) {
                cout << "From: " << char('a' + x1) << y1 + 1 << ", To: " << char('a' + x2) << y2 + 1 << endl;
                return;
            }
        }
    }
    // no move left, surrender
    board->getGame()->setState(GAME_OVER);
    board->getGame()->setTurn(getColor() == BLUE ? RED : BLUE);
}
