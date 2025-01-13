#include <iostream>
#include <vector>

#include "board.h"

using namespace std;
using namespace chess;

int main() {
    Board board;
    board.printBoard();
    board.move("a2");
    return EXIT_SUCCESS;
}