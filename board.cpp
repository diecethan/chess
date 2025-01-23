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
    Board::Board() : currColor(true), p1pts(0), p2pts(0){
        for (int row = 0; row < 8; row++) {
            vector<Piece*> pieces(8, nullptr);
            
            if (row == 0 || row == 7) {
                pieces[0] = (row == 0) ? new Rook(0, 0, true) : new Rook(7, 0, false);
                pieces[1] = (row == 0) ? new Knight(0, 1, true) : new Knight(7, 1, false);
                pieces[2] = (row == 0) ? new Bishop(0, 2, true) : new Bishop(7, 2, false);
                pieces[3] = (row == 0) ? new Queen(0, 3, true) : new Queen(7, 3, false);
                pieces[4] = (row == 0) ? new King(0, 4, true) : new King(7, 4, false);
                pieces[5] = (row == 0) ? new Bishop(0, 5, true) : new Bishop(7, 5, false);
                pieces[6] = (row == 0) ? new Knight(0, 6, true) : new Knight(7, 6, false);
                pieces[7] = (row == 0) ? new Rook(0, 7, true) : new Rook(7, 7, false);
            }
            else if (row == 1 || row == 6) {
                for (int col = 0; col < 8; col++) {
                    pieces[col] = (row == 1) ? new Pawn(row, col, true) : new Pawn(row, col, false);
                }
            }

            board.push_back(pieces);
        }

        whiteKing[0] = 0;
        whiteKing[1] = 4;
        blackKing[0] = 7;
        blackKing[1] = 4;
    }

    void Board::printBoard() const {
        cout << "  ";
        for (int col = 0; col < 8; col++) {
            cout << static_cast<char>(col + 97) << " ";
        }
        cout << endl;

        for (int row = 7; row >= 0; row--) {
            cout << row + 1 << " ";
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
        int srcRow = src[1] - 49;
        int srcCol = src[0] - 97;

        int dstRow = dst[1] - 49;
        int dstCol = dst[0] - 97;
        
        Piece* piece = getPiece(srcRow, srcCol);
        if (piece == nullptr || piece->getColor() != currColor) {
            return false;
        }

        // and current player's king will not be in check
        if (piece->legalMove(*this, dstRow, dstCol)) {     
            // En Passant updating and checking       
            if (!updatePieces.empty()) {
                for (int i = 0; i < updatePieces.size(); i++) {
                    static_cast<Pawn*>(updatePieces[i])->setPassant(false);
                }
                updatePieces.clear();
            }

            if (piece->getPoints() == 1) {
                if (static_cast<Pawn*>(piece)->getPassant()) {
                    updatePieces.push_back(piece);
                }

                if (board[dstRow][dstCol] == nullptr &&  srcCol != dstCol) {
                    delete board[dstRow][srcCol];
                    board[dstRow][srcCol] = nullptr;
                }
            }

            // Basic updating and checking
            if (board[dstRow][dstCol] != nullptr) {
                if (currColor) {
                    p1pts += board[dstRow][dstCol]->getPoints();
                } else {
                    p2pts += board[dstRow][dstCol]->getPoints();
                }
                delete board[dstRow][dstCol];
            }

            piece->setRow(dstRow);
            piece->setCol(dstCol);

            board[dstRow][dstCol] = piece;
            board[srcRow][srcCol] = nullptr;

            if (piece->getPoints() == 0) {
                if (currColor) {
                    whiteKing[0] = dstRow;
                    whiteKing[1] = dstCol;
                } else {
                    blackKing[0] = dstRow;
                    blackKing[1] = dstCol;
                }
            }

            currColor = !currColor;
            return true;
        }

        currColor = !currColor;
        return false;
    }

    bool Board::theoreticalMove(Piece* piece, int srcRow, int srcCol, int dstRow, int dstCol) {
        board[dstRow][dstCol] = piece;
        board[srcRow][srcCol] = nullptr;

        bool result;
        if (currColor) {
            result = static_cast<King*>(getPiece(whiteKing[0], whiteKing[1]))->inCheck(*this);
        } else {
            result = static_cast<King*>(getPiece(blackKing[0], blackKing[1]))->inCheck(*this);
        }

        board[srcRow][srcCol] = piece;
        board[dstRow][dstCol] = nullptr;

        return result;
    }
}
