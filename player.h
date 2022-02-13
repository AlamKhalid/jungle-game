#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "piece.h"
#include "board.h"

using std::string;
using std::vector;

/* abstract base class */
class Player
{
private:
    string name;
    Color color;
    vector<Piece*> pieces;
public:
    Player(string name, Color color);
    string getName() const;
    Color getColor() const;
    int getPieceCount() const;
    Piece* getPiece(int i) const;
    void addPiece(Piece* p);
    void delPiece(Piece* p);
    virtual void makeMove(Board* board) = 0;  // abstract
};

#endif /* PLAYER_H */
