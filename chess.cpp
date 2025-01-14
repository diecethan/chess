#include <iostream>
#include <vector>

#include "board.h"

using namespace std;
using namespace chess;

int main() {
    Board board;
    board.printBoard();
    board.move("g2", "g4");
    board.printBoard();
    return EXIT_SUCCESS;
}