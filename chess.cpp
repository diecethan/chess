#include <iostream>
#include <vector>

#include "board.h"

using namespace std;
using namespace chess;

int main() {
    Board board;
    board.printBoard();
    
    while (true) {
        string src, dst;
        if (board.getCurrPlayer()) {
            cout << "White to move (format: [source destination] [e2 e4])" << endl;
            cout << "To castle, use the King as the source and destination [e1 c1]" << endl;
        } else {
            cout << "Black to move (format: [source destination] [e2 e4]) (to castle, use the King as the source and destination)" << endl;
            cout << "To castle, use the King as the source and destination [e1 c1]" << endl;
        }

        cin >> src >> dst;

        if (board.move(src, dst)) {
            board.printBoard();
        } else {
            cout << "Illegal move!" << endl;
        }
    }

    return EXIT_SUCCESS;
}