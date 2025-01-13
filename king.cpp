#include <iostream>
#include "piece.h"
#include "king.h"
#include "board.h"

using namespace std;

namespace chess {
    bool King::legalMove(Board &board, int row, int col) {
        return true;
    }

    void King::printPiece() {
        if (getColor() == 0) {
            cout << "♔";
        } else {
			cout << "♚";
        }
	}
}