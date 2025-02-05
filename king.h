#ifndef KING_H
#define KING_H

#include "piece.h"
#include "board.h"

namespace chess {
    class King : public Piece {
        public:
            King(int row, int col, bool player) : Piece(row, col, player, 0, 'K') {}
            bool legalMove(Board &board, int row, int col);
            void printPiece();
            bool inCheck(const Board &board);
            bool checkmate(Board &board);
        private:
            bool hasMoved = false;
    };
}

#endif