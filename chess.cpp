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
    cout << "=====================================" << endl << endl;
}

int main() {
    printWelcomeMessage();

    Board board;
    board.printBoard();

    while (!board.checkmate()) {
        string src, dst;
        
        cout << (board.getCurrPlayer() ? "\nWhite to move: " : "\nBlack to move: ");
        
        if (!(cin >> src >> dst)) {  
            // Handle input failure (e.g., user enters EOF or non-string data)
            cout << "Invalid input! Please enter moves in the format [e2 e4]." << endl;
            cin.clear();  // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
            continue;
        }
    
        // Validate that the input is exactly two characters long (e.g., "e2" and "e4")
        if (src.length() != 2 || dst.length() != 2) {
            cout << "Invalid move format! Please enter moves in standard chess notation (e.g., e2 e4)." << endl;
            continue;
        }
    
        // Validate that input follows chess notation (a-h and 1-8)
        if (!(src[0] >= 'a' && src[0] <= 'h' && src[1] >= '1' && src[1] <= '8') ||
            !(dst[0] >= 'a' && dst[0] <= 'h' && dst[1] >= '1' && dst[1] <= '8')) {
            cout << "Invalid move! Coordinates must be in range a1-h8." << endl;
            continue;
        }
    
        cout << endl;
    
        if (board.move(src, dst)) {
            board.printBoard();
        } else {
            cout << "Illegal move!" << endl;
        }
    }

    cout << "Checkmate! " << (board.getCurrPlayer() ? "Black wins!" : "White wins!")<< endl;

    return EXIT_SUCCESS;
}