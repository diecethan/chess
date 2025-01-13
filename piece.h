#ifndef PIECE_H
#define PIECE_H

namespace chess {
    class Board;
    
    class Piece {
        public:
            virtual ~Piece() {}
            Piece(int r, int c, int clr, int p) : row(r), col(c), color(clr), points(p) {}

            int getRow() const { return row; }
            int getCol() const { return col; }
            int getColor() const { return color; }
            int getPoints() const { return points; }

            virtual void printPiece() = 0;
            virtual bool legalMove(Board &board, int row, int col) = 0;
        protected:
            int row, col;
            int color;
            int points;
    };
}

#endif