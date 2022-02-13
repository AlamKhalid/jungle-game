#include <iostream>
#include <cctype>
#include "game.h"
#include "board.h"
#include "piece.h"
#include "elephant.h"
#include "lion.h"
// TODO: include more necessary headers
#include "tiger.h"
#include "leopard.h"
#include "wolf.h"
#include "dog.h"
#include "cat.h"
#include "rat.h"
#include "fileman.h"

using namespace std;

Board::Board(Game* game, char* filename) : 
    game(game), cells() {  // initalize cells' elements to nullptr
    // Set up the initial game board
    if (filename != nullptr)
        loadFromFile(filename, this);
    else
        init();
}

// initial gameboard configuration
void Board::init() {
    // TODO:
    // set up the Jungle chess standard initial gameboard properly;
    // add Elephants, Lions, ..., Rats to the cells array at correct positions
    // nullify each cell first using EMPTY
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            cells[i][j] = EMPTY;
    // get players
    Player* blue = game->getPlayer(BLUE);
    Player* red = game->getPlayer(RED);
    // blue pieces adding to cell
    cells[0][0] = new Lion(BLUE,0,0);
    cells[0][6] = new Tiger(BLUE, 0, 6);
    cells[1][1] = new Dog(BLUE, 1, 1);
    cells[1][5] = new Cat(BLUE, 1, 5);
    cells[2][0] = new Rat(BLUE, 2, 0);
    cells[2][2] = new Leopard(BLUE, 2, 2);
    cells[2][4] = new Wolf(BLUE, 2, 4);
    cells[2][6] = new Elephant(BLUE, 2, 6);
    // red pieces adding to cell
    cells[6][0] = new Elephant(RED, 6, 0);
    cells[6][2] = new Wolf(RED, 6, 2);
    cells[6][4] = new Leopard(RED, 6, 4);
    cells[6][6] = new Rat(RED, 6, 6);
    cells[7][1] = new Cat(RED, 7, 1);
    cells[7][5] = new Dog(RED, 7, 5);
    cells[8][0] = new Tiger(RED,8,0);
    cells[8][6] = new Lion(RED, 8, 6);
    // TODO: also add the created pieces to each player's vector of pieces
    // blue pieces adding to vector
    blue->addPiece(cells[0][0]);
    blue->addPiece(cells[0][6]);
    blue->addPiece(cells[1][1]);
    blue->addPiece(cells[1][5]);
    blue->addPiece(cells[2][0]);
    blue->addPiece(cells[2][2]);
    blue->addPiece(cells[2][4]);
    blue->addPiece(cells[2][6]);
    // red pieces adding to vector
    red->addPiece(cells[6][0]);
    red->addPiece(cells[6][2]);
    red->addPiece(cells[6][4]);
    red->addPiece(cells[6][6]);
    red->addPiece(cells[7][1]);
    red->addPiece(cells[7][5]);
    red->addPiece(cells[8][0]);
    red->addPiece(cells[8][6]);
}

// Return true if (y, x) is an empty cell, and false otherwise
bool Board::isEmpty(int y, int x) {
    if (cells[y][x] == EMPTY)
        return true;
    return false;
}

// Return true if (y, x) is the den on the side of the specified color, 
// and false otherwise
bool Board::isDen(int y, int x, Color color) {
    // TODO: Add your code here
    if (color == BLUE) {
        if (y == 0 && x == 3) return true;
        return false;
    }
    else {
        if (y == 8 && x == 3) return true;
        return false;
    }
}

// Return true if (y, x) is a trap on the side of the specified color, 
// and false otherwise
bool Board::isTrap(int y, int x, Color color) {
    // TODO: Add your code here
    if (color == BLUE) {
        if (y == 0) if (x == 2 || x == 4) return true;
        if (y == 1 && x == 3) return true;
        return false;
    }
    else {
        if (y == 8) if (x == 2 || x == 4) return true;
        if (y == 7 && x == 3) return true;
        return false;
    }
}

// Return true if (y, x) is a river cell, and false otherwise
bool Board::isRiver(int y, int x) {
    return y >= 3 && y <= 5 && (x >= 1 && x <= 2 || x >= 4 && x <= 5);
}

// Get a piece from the specified cell
Piece* Board::get(int y, int x){
    if (0 <= y && y < H && 0 <= x && x < W)
        return cells[y][x];
    return OUT_BOUND; // out of bound
}

// Put piece p onto the specified cell
void Board::put(int y, int x, Piece* p){
    cells[y][x] = p;
    if (p != EMPTY) {
        p->setY(y);
        p->setX(x);
    }
}

// Print the gameboard
void Board::print() {
    // TODO: Add code to print the HxW gameboard by looping over cells array
    // Hint: Make use of isEmpty(), isRiver(), isTrap(), isDen(), and 
    //       getLabel() of Piece to ease your work
    // Remember * for river cells, # for trap cells, X for den cells
    cout << "    A   B   C   D   E   F   G" << endl;
    cout << "  +---+---+---+---+---+---+---+" << endl;
    for (int i = 0; i < H; i++) {
        cout<< i + 1<<" ";
        for (int j = 0; j < W; j++) {
            cout <<"|";
            // first get piece
            Piece* p = cells[i][j];
            if (p != EMPTY) cout <<" "<< p->getLabel()<<" ";
            else if (isTrap(i, j, BLUE) || isTrap(i, j, RED)) cout << " # ";
            else if (isDen(i, j, BLUE) || isDen(i, j, RED)) cout << " X ";
            else if (isRiver(i, j)) cout << " * ";
            else cout << "   ";
        }
        cout << "|\n  +---+---+---+---+---+---+---+" << endl;
    }
}

// Check if the move from (y1, x1) to (y2, x2) is valid
bool Board::isMoveValid(int y1, int x1, int y2, int x2) {
    // TODO:
    // check against invalid cases, for example,
    // - the source is an empty cell
    // - the source and destination are the same position
    // - the destination is out of bound of the board (hint: use OUT_BOUND)
    // - the source piece is not of same color of current turn of the game
    // (... and anymore ?)
    // [Note: you can modify the following code if it doesn't fit your design]
    Piece* p = cells[y1][x1];
    Piece* o = cells[y2][x2];
    if (p == EMPTY) return false;
    if (y1 == y2 && x1 == x2) return false;
    if (y2 < 0 || y2 > 8 || x2 < 0 || x2 > 6) return false;
    if (p->getColor() != game->getTurn()) return false;
    if (o != EMPTY && o->getColor() == p->getColor()) return false;
    if (isDen(y2,x2,p->getColor())) return false;
    // Piece-specific validation
    if (p->isMoveValid(this, y2, x2) == false)
        return false;
    return true;
}

// Carry out the move from (y1, x1) to (y2, x2)
bool Board::move(int y1, int x1, int y2, int x2) {
    if (isMoveValid(y1, x1, y2, x2)) {
        get(y1, x1)->move(this, y2, x2);
        return true;
    }
    return false;
}

// Return the pointer to the Game object
Game* Board::getGame() const {
    return game;
}
