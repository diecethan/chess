#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"
#include "board.h"

namespace chess {
    class Bishop : public Piece {
        public:
            Bishop(int row, int col, bool player) : Piece(row, col, player, 3, 'B') {}
            bool legalMove(Board &board, int row, int col);
            void printPiece();
    };
}

#endif