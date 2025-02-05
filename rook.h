#ifndef ROOK_H
#define ROOK_H

#include "piece.h"
#include "board.h"

namespace chess {
    class Rook : public Piece {
        public:
            Rook(int row, int col, bool player) : Piece(row, col, player, 5, 'R') {}
            bool legalMove(Board &board, int row, int col);
            void printPiece();
            bool canCastle() { return !hasMoved; }
        private:
            bool hasMoved = false;
    };
}

#endif