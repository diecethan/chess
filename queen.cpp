#include <iostream>
#include "piece.h"
#include "queen.h"
#include "board.h"

using namespace std;

namespace chess {
    bool Queen::legalMove(Board &board, int row, int col) {
        return true;
    }

    void Queen::printPiece() {
        if (getColor() == 0) {
            cout << "♕";
        } else {
			cout << "♛";
        }
	}
}