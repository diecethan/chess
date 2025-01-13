#include <iostream>
#include "piece.h"
#include "rook.h"
#include "board.h"

using namespace std;

namespace chess {
    bool Rook::legalMove(Board &board, int row, int col) {
        return true;
    }

    void Rook::printPiece() {
        if (getColor() == 0) {
            cout << "♖";
        } else {
			cout << "♜";
        }
	}
}