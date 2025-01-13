#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>
#include "piece.h"

namespace chess {
    class Board {
        public:
            Board();
            void printBoard() const;
            Piece* getPiece(int row, int col) const { return board[row][col]; }
            void move(std::string input);

        private:
            std::vector<std::vector<Piece*>> board;
    };
}

#endif