#include <cstdio>
#include <iostream>
#include <iomanip>

#include "piece.h"
#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"

using namespace std;

namespace chess {
    Board::Board() {

    }

    void Board::print() {
        for (int row = 0; row < board.size(); row++) {
            cout << board.at(row) << endl;
        }
    }
}
