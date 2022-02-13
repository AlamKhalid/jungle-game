#include <iostream>
#include <fstream>	// std::ifstream
#include <cctype>
#include "fileman.h"
#include "piece.h"
#include "elephant.h"
#include "lion.h"
#include "tiger.h"
#include "leopard.h"
#include "wolf.h"
#include "dog.h"
#include "cat.h"
#include "rat.h"

using namespace std;

// for loading a board initial configuration file into the board
void loadFromFile(const char* filename, Board* board)
{
	ifstream fin(filename);

	// Terminate if the file cannot be opened for reading
	if (fin.fail()) {
		cout << "File " << filename << " could not be opened" << endl;
		exit(1);  
	}

	int row, r, c;
	char col, label;
	while (!fin.eof()) {
		fin >> col >> row >> label;
		if (fin.fail() && !fin.eof()) {
			cout << "Error in reading the data file!\n";
			exit(1);	// Stop reading immediately
		}
		if (fin.fail())
			break;
		c = col - 'A';
		r = row - 1;
		if (r < 0 || r > Board::H - 1 || c < 0 || c > Board::W - 1) {
			cout << "Invalid file data found!\n";
			exit(1);	// Stop reading immediately
		}
		Piece* p;
		Color color = isupper(label) ? RED : BLUE;
		switch (toupper(label)) {
		case 'E':
			p = new Elephant(color, r, c);
			break;
		case 'L':
			p = new Lion(color, r, c);
			break;
		case 'T':
			p = new Tiger(color, r, c);
			break;
		case 'P':
			p = new Leopard(color, r, c);
			break;
		case 'W':
			p = new Wolf(color, r, c);
			break;
		case 'D':
			p = new Dog(color, r, c);
			break;
		case 'C':
			p = new Cat(color, r, c);
			break;
		case 'R':
			p = new Rat(color, r, c);
			break;
		default:
			cout << "Invalid animal label in file found!" << endl;
			exit(1);
		}
		board->put(r, c, p);
		// Basic validation
		if (board->isTrap(r, c, Color(1 - color)))
			p->setTrapped(true);
		if (board->isRiver(r, c) && p->getRank() != RAT) {
			cout << "Invalid input! Only rats can be put in river!" << endl;
			exit(1);
		}
		if (board->isDen(r, c, color)) {
			cout << "Invalid input! Animals can't be put in their own den!" << endl;
			exit(1);
		}
		board->getGame()->getPlayer(color)->addPiece(p);
	}
	fin.close();
}