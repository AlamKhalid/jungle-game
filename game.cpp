#include <iostream>
#include "game.h"
#include "human.h"
#include "machine.h"
// TODO (Optional): add header, e.g. greedymachine.h if you've implemented a greedy machine

using namespace std;

Game::Game(Mode mode, char* filename) : state(RUNNING) {
    Player* blue = (Player*) (mode == M2M) ? 
        (Player*) new Machine("Blue", BLUE) : (Player*) new Human("Blue", BLUE);

    Player* red  = (Player*) (mode == H2H) ? 
        (Player*) new Human("Red", RED) : (Player*) new Machine("Red", RED);
    /* TODO (Optional): change this line from Machine to GreedyMachine if you have, 
       then RED player is supposed to be "cleverer" in terms of move strategy
     */

    players[0] = blue;
    players[1] = red;
    turn = BLUE;
    board = new Board(this, filename);
}

Player* Game::getPlayer(Color color) const {
    return players[int(color)];
}

Color Game::getTurn() const {
    return turn;
}

void Game::setTurn(Color turn) {
    this->turn = turn;
}

State Game::getState() const {
    return state;
}

void Game::setState(State state) {
    this->state = state;
}

void Game::run() {
    for (int round = 1; state == RUNNING ; round++)  {
        cout << "Round " << round << ":" << endl;
        board->print();                   // print game board
        getPlayer(turn)->makeMove(board); // move a chess piece
        if (state == RUNNING)
            turn = Color(1 - int(turn));  // flip turns
    }
    // Game over
    cout << "Game over:" << endl;
    board->print();
    
    // TODO: print who wins
    // (assumed the winner is the player who made the last turn)
    cout << "Winner is ";
    if (turn == 0) cout << "Blue";
    else cout << "Red";
    cout << endl;
}
