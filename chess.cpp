#include <iostream>
#include <vector>

#include "board.h"

using namespace std;
using namespace chess;

void printWelcomeMessage() {
    cout << "=====================================" << endl;
    cout << "         Welcome to Chess!           " << endl;
    cout << "=====================================" << endl;
    cout << "Move Format: Enter source and destination squares (e.g., e2 e4)." << endl;
    cout << " - Example: 'e2 e4' moves a piece from e2 to e4." << endl;
    cout << " - Capture moves follow the same format." << endl;
    cout << " - Promotion: Enter the move normally; the game will handle it." << endl;
    cout << " - Castling: Use the King’s position for both source and destination." << endl;
    cout << "   - Kingside: e1 g1 (White) | e8 g8 (Black)" << endl;
    cout << "   - Queenside: e1 c1 (White) | e8 c8 (Black)" << endl;
    cout << " - En Passant is automatically detected." << endl;
    cout << "To win, checkmate your opponent’s King!" << endl;
    cout << "=====================================" << endl;
}

int main() {
    printWelcomeMessage();

    Board board;
    board.printBoard();

    while (true) {
        string src, dst;
        
        cout << (board.getCurrPlayer() ? "\nWhite to move: " : "\nBlack to move: ");
        cin >> src >> dst;
        cout << endl;

        if (board.move(src, dst)) {
            board.printBoard();
        } else {
            cout << "Illegal move!" << endl;
        }
    }

    return EXIT_SUCCESS;
}