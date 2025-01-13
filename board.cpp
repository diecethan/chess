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
                pieces[0] = (row == 0) ? new Rook(0, 0, false) : new Rook(7, 0, true);
                pieces[1] = (row == 0) ? new Knight(0, 1, false) : new Knight(7, 1, true);
                pieces[2] = (row == 0) ? new Bishop(0, 2, false) : new Bishop(7, 2, true);
                pieces[3] = (row == 0) ? new Queen(0, 3, false) : new Queen(7, 3, true);
                pieces[4] = (row == 0) ? new King(0, 4, false) : new King(7, 4, true);
                pieces[5] = (row == 0) ? new Bishop(0, 5, false) : new Bishop(7, 5, true);
                pieces[6] = (row == 0) ? new Knight(0, 6, false) : new Knight(7, 6, true);
                pieces[7] = (row == 0) ? new Rook(0, 7, false) : new Rook(7, 7, true);
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
                } else {
                    cout << "  ";
                }

            }
            cout << endl;
        }
    }

    bool Board::move(string src, string dst) {
        int srcRow = src[0] - 97;
        int srcCol = src[1] - 49;

        int dstRow = dst[0] - 97;
        int dstCol = dst[1] - 49;

        Piece* piece = getPiece(srcRow, srcCol);
        cout << currColor << endl;
        if (piece == nullptr || piece->getColor() != currColor) {
            // throw error
            return false;
        }

        // and current player's king will not be in check
        if (piece->legalMove(*this, dstRow, dstCol)) {
            if (board[dstRow][dstCol] != nullptr) {
                delete board[dstRow][dstCol];
            }

            piece->setRow(dstRow);
            piece->setCol(dstCol);

            board[dstRow][dstCol] = piece;
            board[srcRow][srcCol] = nullptr;
            
            currColor = !currColor;
            return true;
        }
        
        currColor = !currColor;
        return false;
    }
}
