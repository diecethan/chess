#include <iostream>
#include "piece.h"
#include "king.h"
#include "rook.h"
#include "board.h"

using namespace std;

namespace chess {
    bool King::legalMove(Board &board, int row, int col) {
        // castling
        if (abs(getCol() - col) > 1) {
            if (!hasMoved && !inCheck(board)) {
                Piece* piece;
                Rook* rook;
            
                if (getCol() < col) {
                    piece = board.getPiece(row, col + 1);
                    rook = dynamic_cast<Rook*>(piece);
                } else {
                    piece = board.getPiece(row, col - 2);
                    rook = dynamic_cast<Rook*>(piece);
                }

                if (!rook) {
                    return false;
                }

                if (rook->canCastle() && rook->getColor() == getColor()) {
                    if (getCol() < col) {
                        for (int column = getCol() + 1; column < col; column++) {
                            if (board.getPiece(row, column) != nullptr) {
                                return false;
                            }
                        }
                    } else {
                        for (int column = getCol() - 1; column > col; column--) {
                            if (board.getPiece(row, column) != nullptr) {
                                return false;
                            }
                        }
                    }
                }

                hasMoved = true;
                return true;
            }
        }

        // King trying to move up
        if (abs(getRow() - row) > 1) {
            return false;
        }
        
        // Check (if there is a piece) if we can take the piece or not
        if (board.getPiece(row, col) != nullptr && board.getPiece(row, col)->getColor() == getColor()) {
            return false;
        }

        // Checks that this move does not put the King in check
        if (board.theoreticalMove(this, getRow(), getCol(), row, col)) {
            return false;
        }

        hasMoved = true;
        return true;
    }

    bool King::inCheck(const Board &board) {
        // Knight checks
        int knightDirs[8][2] = { {2, 1}, {2, -1}, {-2, 1}, {2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2} };
        for (auto &dir : knightDirs) {
            int checkRow = row + dir[0];
            int checkCol = col + dir[1];

            if (checkRow >= 0 && checkRow < 8 && checkCol >= 0 && checkCol < 8) {
                Piece* checkPiece = board.getPiece(checkRow, checkCol);
                if (checkPiece != nullptr && checkPiece->getColor() != color && checkPiece->getSymbol() == 'N') {
                    return true;
                }
            }
        }

        // Rook/Queen checks
        int straightDirs[4][2] = { {1, 0}, {-1, 0}, {0, 1} , {0, -1} };
        for (auto &dir : straightDirs) {
            int inc = 1;
            while (true) {
                int checkRow = row + dir[0] * inc;
                int checkCol = col + dir[1] * inc;

                if (checkRow < 0 || checkRow >= 8 || checkCol < 0 || checkCol >= 8) {
                    break;
                }

                Piece* checkPiece = board.getPiece(checkRow, checkCol);
                if (checkPiece != nullptr) {
                    if (checkPiece->getColor() != color && (checkPiece->getSymbol() == 'R' || checkPiece->getSymbol() == 'Q')) {
                        return true;
                    }
                    break;
                }
                inc++;
            }
        }

        // Bishop/Queen checks
        int diagDirs[4][2] = { {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };
        for (auto &dir : diagDirs) {
            int inc = 1;
            while (true) {
                int checkRow = row + dir[0] * inc;
                int checkCol = col + dir[1] * inc;

                if (checkRow < 0 || checkRow >= 8 || checkCol < 0 || checkCol >= 8) {
                    break;
                }

                Piece* checkPiece = board.getPiece(checkRow, checkCol);
                if (checkPiece != nullptr) {
                    if (checkPiece->getColor() != color && (checkPiece->getSymbol() == 'B' || checkPiece->getSymbol() == 'Q')) {
                        return true;
                    }
                    break;
                }
                inc++;
            }
        }

        // Pawn checks
        int pawnDirs[2][2] = { {-1, -1}, {-1, 1} };
        
        // Direction based on color
        if (color == 1) {
            pawnDirs[0][0] = 1; 
            pawnDirs[1][0] = 1;
        }
        
        for (auto &dir : pawnDirs) {
            int checkRow = row + dir[0];
            int checkCol = col + dir[1];
            if (checkRow >= 0 && checkRow < 8 && checkCol >= 0 && checkCol < 8) {
                Piece* checkPiece = board.getPiece(checkRow, checkCol);
                if (checkPiece != nullptr) {
                    if (checkPiece->getColor() != color && checkPiece->getSymbol() == 'P') {
                        return true;
                    }
                }
            }
        }

        return false;
    }
    
    void King::printPiece() {
        if (getColor()) {
			cout << "♚";
        } else {
            cout << "♔";
        }
	}
}