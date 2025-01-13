#include <iostream>
#include "piece.h"
#include "bishop.h"
#include "board.h"

using namespace std;

namespace chess {
    bool Bishop::legalMove(Board &board, int row, int col) {
        // source = destination
        if (getRow() == row && getCol() == col) {
            return false;
        }

        // Check that the piece moved diagonally
        if (abs(getRow() - row) != abs(getCol() - col)) {
            return false;
        }

        // Check that there are no pieces along the path from source to destination
        // Checks the direction the Bishop traveled in, then iterates from source to destination
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

        // Check (if there is a piece) if we can take the piece or not
        if (board.getPiece(row, col) != nullptr && board.getPiece(row, col)->getColor() == getColor()) {
            return false;
        }

        return true;
    }

    void Bishop::printPiece() {
        if (getColor()) {
			cout << "♝";
        } else {
            cout << "♗";
        }
	}
}