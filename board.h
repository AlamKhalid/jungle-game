#ifndef BOARD_H
#define BOARD_H

class Game;         // forward declaration
class Piece;        // forward declaration
enum Color : int;   // forward declaration

Piece* const EMPTY = nullptr;  // represents an empty cell
Piece* const OUT_BOUND = (Piece*) -1; /* a special address representing
                                         out of the board's boundaries */

class Board
{
public:
    const static int W = 7;  // board width
    const static int H = 9;  // board height
    Board(Game* game, char* filename);
    void init();
    bool isEmpty(int y, int x);
    bool isDen(int y, int x, Color color);
    bool isTrap(int y, int x, Color color);
    bool isRiver(int y, int x);
    Piece* get(int y, int x);
    void put(int y, int x, Piece* p);
    void print();
    bool isMoveValid(int y1, int x1, int y2, int x2);
    bool move(int y1, int x1, int y2, int x2);
    Game* getGame() const;  // back link to Game object
private:
    Piece* cells[H][W];
    Game* game; // back link to the game
};

#endif
