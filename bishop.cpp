#include <iostream>
#include "piece.h"
#include "bishop.h"
#include "board.h"

using namespace std;

namespace chess {
    bool Bishop::legalMove(Board &board, int row, int col) {
        return true;
    }

    void Bishop::printPiece() {
        if (getColor() == 0) {
            cout << "♗";
        } else {
			cout << "♝";
        }
	}
}