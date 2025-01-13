#include <iostream>
#include "piece.h"
#include "knight.h"
#include "board.h"

using namespace std;

namespace chess {
    bool Knight::legalMove(Board &board, int row, int col) {
        // Check that the move follows the correct Knight movement
        // Check (if there is a piece) if we can take the piece or not
        if (abs(getRow() - row) == 1 && abs(getCol() - col) == 2) {
            if (board.getPiece(row, col) != nullptr && board.getPiece(row, col)->getColor() == getColor()) {
                return false;
            }

            return true;
        }

        if (abs(getRow() - row) == 2 && abs(getCol() - col) == 1) {
            if (board.getPiece(row, col) != nullptr && board.getPiece(row, col)->getColor() == getColor()) {
                return false;
            
            }
            
            return true;
        }

        return false;
    }

    void Knight::printPiece() {
        if (getColor()) {
			cout << "♞";
        } else {
            cout << "♘";
        }
    }
}