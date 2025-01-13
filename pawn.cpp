#include <iostream>
#include "piece.h"
#include "pawn.h"
#include "board.h"

using namespace std;

namespace chess {
    bool Pawn::legalMove(Board &board, int row, int col) {
        return true;
    }

    void Pawn::printPiece() {
        if (getColor() == 0) {
            cout << "♙";
        } else {
			cout << "♟";
        }
	}
}