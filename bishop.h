#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"
#include "board.h"

namespace chess {
    class Bishop : public Piece {
        public:
            Bishop(int row, int col, int player) : Piece(row, col, player, 3) {}
            bool legalMove(Board &board, int row, int col);
            bool check(Board &board);
            void printPiece();
    };
}

#endif