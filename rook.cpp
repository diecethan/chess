#include <iostream>
#include "piece.h"
#include "rook.h"
#include "board.h"

using namespace std;

namespace chess {
    bool Rook::legalMove(Board &board, int row, int col) {
        // source = destination
        if (getRow() == row && getCol() == col) {
            return false;
        }

        // Check that the piece only moved up/down or right/left
        if (getRow() != row && getCol() != col) {
            return false;
        }

        // Check that there are no pieces along the path from source to destination
        // Checks the direction the Rook traveled in, then iterates from source to destination
        bool traversalDir = getRow() == row;
        if (traversalDir) {
            if (getCol() < col) {
                for (int i = getCol() + 1; i < col; i++) {
                    if (board.getPiece(row, i) != nullptr) {
                        return false;
                    }
                }
            } else {
                for (int i = getCol() - 1; i > col; i--) {
                    if (board.getPiece(row, i) != nullptr) {
                        return false;
                    }
                }
            }
        } else {
            if (getRow() < row) {
                for (int i = getRow() + 1; i < row; i++) {
                    if (board.getPiece(i, col) != nullptr) {
                        return false;
                    }
                }
            } else {
                for (int i = getRow() - 1; i > row; i--) {
                    if (board.getPiece(i, col) != nullptr) {
                        return false;
                    }
                }
            }
        }
        
        // Check (if there is a piece) if we can take the piece or not
        if (board.getPiece(row, col) != nullptr && board.getPiece(row, col)->getColor() == getColor()) {
            return false;
        }

        // Checks that this move does not reveal a discovered check
        if (board.theoreticalMove(this, getRow(), getCol(), row, col, false)) {
            return false;
        }
        
        hasMoved = true;
        return true;
    }

    void Rook::printPiece() {
        if (getColor()) {
			cout << "♜";
        } else {
            cout << "♖";
        }
	}
}