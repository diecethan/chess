#include <iostream>
#include "piece.h"
#include "bishop.h"
#include "board.h"

using namespace std;

namespace chess {
    bool Bishop::legalMove(Board &board, int row, int col) {
        if (getRow() == row && getCol() == col) {
            return false;
        }

        if (abs(getRow() - row) == abs(getCol() - col)) {
            return true;
        }

        return false;
    }

    void Bishop::printPiece() {
        if (getColor()) {
			cout << "♝";
        } else {
            cout << "♗";
        }
	}
}