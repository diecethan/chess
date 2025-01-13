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

        if (getRow() != row && getCol() != col) {
            return false;
        }

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
        
        if (board.getPiece(row, col) != nullptr && board.getPiece(row, col)->getColor() == getColor()) {
            return false;
        }
        
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