#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>
#include "piece.h"

namespace chess {
    class Pawn;
    class Board {
        public:
            Board();
            void printBoard() const;
            Piece* getPiece(int row, int col) const { return board[row][col]; }
            bool move(std::string src, std::string dst);
            bool theoreticalMove(Piece* piece, int srcRow, int srcCol, int dstRow, int dstCol);   // Checks for checks
            bool getCurrPlayer() { return currColor; }

        private:
            std::vector<std::vector<Piece*>> board;
            std::vector<Piece*> updatePieces;   // used to reset en passantability after one turn
            bool currColor;
            int p1pts, p2pts;
            int whiteKing[2];
            int blackKing[2];
    };
}

#endif