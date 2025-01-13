#include <iostream>
#include "piece.h"
#include "queen.h"
#include "board.h"

using namespace std;

namespace chess {
    bool Queen::legalMove(Board &board, int row, int col) {
        if (getRow() != row && getCol() != col) {
            if (abs(getRow() - row) != abs(getCol() - col)) {
                return false;
            }
            return true;
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