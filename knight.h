#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"
#include "board.h"

namespace chess {
    class Knight : public Piece {
        public:
            Knight(int row, int col, bool player) : Piece(row, col, player, 3) {}
            bool legalMove(Board &board, int row, int col);
            void printPiece();
    };
}

#endif