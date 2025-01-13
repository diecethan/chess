#ifndef KING_H
#define KING_H

#include "piece.h"
#include "board.h"

namespace chess {
    class King : public Piece {
        public:
            King(int row, int col, int player) : Piece(row, col, player, 0) {}
            bool legalMove(Board &board, int row, int col);
            void printPiece();
    };
}

#endif