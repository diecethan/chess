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
    board.move("f1", "e2");
    board.printBoard();
    board.move("d8", "f6");
    board.printBoard();
    board.move("a2", "a3");
    board.printBoard();
    board.move("f6", "f3");
    board.printBoard();
    board.move("b2", "b3");
    board.printBoard();
    board.move("f3", "e3");
    board.printBoard();
    board.move("e2", "e3");
    board.printBoard();
    return EXIT_SUCCESS;
}