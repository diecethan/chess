#include <cstdio>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cctype>

#include "piece.h"
#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"

#include "board.h"

using namespace std;

namespace chess {
    Board::Board() {
        for (int row = 0; row < 8; row++) {
            vector<Piece*> pieces(8, nullptr);
            
            if (row == 0 || row == 7) {
                pieces[0] = (row == 0) ? new Rook(0, 0, 0) : new Rook(7, 0, 1);
                pieces[1] = (row == 0) ? new Knight(0, 1, 0) : new Knight(7, 1, 1);
                pieces[2] = (row == 0) ? new Bishop(0, 2, 0) : new Bishop(7, 2, 1);
                pieces[3] = (row == 0) ? new Queen(0, 3, 0) : new Queen(7, 3, 1);
                pieces[4] = (row == 0) ? new King(0, 4, 0) : new King(7, 4, 1);
                pieces[5] = (row == 0) ? new Bishop(0, 5, 0) : new Bishop(7, 5, 1);
                pieces[6] = (row == 0) ? new Knight(0, 6, 0) : new Knight(7, 6, 1);
                pieces[7] = (row == 0) ? new Rook(0, 7, 0) : new Rook(7, 7, 1);
            }
            else if (row == 1 || row == 6) {
                for (int col = 0; col < 8; col++) {
                    pieces[col] = (row == 1) ? new Pawn(row, col, 0) : new Pawn(row, col, 1);
                }
            }

            board.push_back(pieces);
        }
    }

    void Board::printBoard() const {
        cout << "  ";
        for (int col = 0; col < 8; col++) {
            cout << (col + 1) << " ";
        }
        cout << endl;

        for (int row = 0; row < 8; row++) {
            cout << static_cast<char>(row + 97) << " ";
            for (int col = 0; col < 8; col++) {
                if (board[row][col] != nullptr) {
                    board[row][col]->printPiece();
                    cout << " ";
                }

            }
            cout << endl;
        }
    }

    void Board::move(string input) {
        char piece;
        int row, col;

        if (input[1] != 'x') {
            piece = (isupper(input[0])) ? input[0] : 'p';
            row = (piece == 'p') ? (input[0] - 97) : (input[1] - 97);
            col = (piece == 'p') ? (input[1] - 49) : (input[2] - 49);
        } else {
            piece = (isupper(input[0])) ? input[0] : 'p';
            row = (piece == 'p') ? (input[1] - 97) : (input[2] - 97);
            col = (piece == 'p') ? (input[2] - 49) : (input[3] - 49);
        }

        cout << piece << " " << row << " " << col << endl;
    }
}
