#include <iostream>
#include <vector>

#include "board.h"

using namespace std;
using namespace chess;

int main() {
    Board board;
    board.printBoard();
    bool x = board.move("h8", "h7");
    cout << x << endl;
    board.printBoard();
    board.move("h7", "h8");
    board.printBoard();
    return EXIT_SUCCESS;
}