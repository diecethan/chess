#include <iostream>
#include <vector>

#include "board.h"

using namespace std;
using namespace chess;

int main() {
    Board board;
    board.printBoard();
    bool x = board.move("h7", "g5");
    board.printBoard();
    return EXIT_SUCCESS;
}