#ifndef ROOK_H
#define ROOK_H

#include "piece.h"
#include "board.h"

namespace chess {
    class Rook : public Piece {
        public:
            Rook(int row, int col, int player) : Piece(row, col, player, 5) {}
            bool legalMove(Board &board, int row, int col);
            void printPiece();
    };
}

#endif