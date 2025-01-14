#include <iostream>
#include "piece.h"
#include "queen.h"
#include "board.h"

using namespace std;

namespace chess {
    bool Queen::legalMove(Board &board, int row, int col) {
        // source = destination
        if (getRow() == row && getCol() == col) {
            return false;
        }

        // Moved horizontally/vertically or diagonally
        bool hor = (getRow() == row) || (getCol() == col);

        // Use Rook or Bishop check based on direction traveled
        if (hor) {
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
        } else {
            bool rowDir = row > getRow();
            bool colDir = col > getCol();
            if (rowDir && colDir) {
                for (int i = 1; i < abs(getRow() - row); i++) {
                    if (board.getPiece(getRow() + i, getCol() + i) != nullptr) {
                        return false;
                    }
                }
            }
            else if (rowDir && !colDir) {
                for (int i = 1; i < abs(getRow() - row); i++) {
                    if (board.getPiece(getRow() + i, getCol() - i) != nullptr) {
                        return false;
                    }
                }
            }
            else if (!rowDir && colDir) {
                for (int i = 1; i < abs(getRow() - row); i++) {
                    if (board.getPiece(getRow() - i, getCol() + i) != nullptr) {
                        return false;
                    }
                }
            }
            else {
                for (int i = 1; i < abs(getRow() - row); i++) {
                    if (board.getPiece(getRow() - i, getCol() - i) != nullptr) {
                        return false;
                    }
                }
            }
        }

        // Check (if there is a piece) if we can take the piece or not
        if (board.getPiece(row, col) != nullptr && board.getPiece(row, col)->getColor() == getColor()) {
            return false;
        }

        return true;
    }

    void Queen::printPiece() {
        if (getColor()) {
			cout << "♛";
        } else {
            cout << "♕";
        }
	}
}