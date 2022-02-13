#include <iostream>
#include "game.h"

using namespace std;

int main(int argc, char* argv[]) {
    char* filename = nullptr;
    if (argc > 1)
        filename = argv[1];

    cout << "Choose game mode (1, 2, 3): ";
    int mode;
    cin >> mode;
    Game game((Mode)mode, filename);
    game.run();
    return 0;
}
