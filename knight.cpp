#include <iostream>
#include "piece.h"
#include "knight.h"
#include "board.h"

using namespace std;

namespace chess {
    bool Knight::legalMove(Board &board, int row, int col) {
        return true;
    }

    void Knight::printPiece() {
        if (getColor() == 0) {
            cout << "♘";
        } else {
			cout << "♞";
        }
	}
}