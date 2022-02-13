#ifndef PIECE_H
#define PIECE_H

#include "board.h"
#include <string>
using std::string;

enum Color : int {BLUE, RED};

enum Rank {RAT=1, CAT, DOG, WOLF, LEOPARD, TIGER, LION, ELEPHANT};

const string PIECE_NAME[] = { "Rat", "Cat", "Dog", "Wolf", "Leopard", 
                              "Tiger", "Lion", "Elephant" };

class Piece
{
private:
    string name;
    Color color;
    int rank;
    int y, x;
    bool trapped;
protected:
    void setName(string name);
    void setRank(int rank);
public:
    Piece(Color color, int y, int x);
    string getName() const;
    virtual char getLabel() const;
    Color getColor() const;
    int getRank() const;
    int getY() const;
    int getX() const;
    void setY(int y);
    void setX(int x);
    bool isTrapped();
    void setTrapped(bool trapped);
    bool isOpponent(Piece* p);
    virtual bool canCapture(Piece* p);
    virtual void capture(Board* board, Piece* p);
    virtual bool isMoveValid(Board* board, int y, int x) = 0; // abstract
    virtual void move(Board* board, int y, int x);
};

#endif  /* PIECE_H */
