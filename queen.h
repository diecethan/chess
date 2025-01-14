#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"
#include "board.h"

namespace chess {
    class Queen : public Piece {
        public:
            Queen(int row, int col, bool player) : Piece(row, col, player, 9, 'Q') {}
            bool legalMove(Board &board, int row, int col);
            void printPiece();
    };
}

#endif