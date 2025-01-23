#include <iostream>
#include <vector>

#include "board.h"

using namespace std;
using namespace chess;

int main() {
    Board board;
    board.printBoard();
    board.move("e2", "e4");
    board.printBoard();
    board.move("e7", "e5");
    board.printBoard();
    board.move("a2", "a3");
    board.printBoard();
    board.move("a7", "a6");
    board.printBoard();
    board.move("e4", "f5");
    board.printBoard();
    board.move("e1", "e2");
    board.printBoard();
    board.move("d8", "g5");
    board.printBoard();
    board.move("e2", "d3");
    board.printBoard();
    return EXIT_SUCCESS;
}