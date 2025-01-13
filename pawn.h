#ifndef PAWN_H
#define PAWN_H

#include "piece.h"
#include "board.h"

namespace chess {
    class Pawn : public Piece {
        public:
            Pawn(int row, int col, bool player) : Piece(row, col, player, 1) {}
            bool legalMove(Board &board, int row, int col);
            void printPiece();
    };
}

#endif