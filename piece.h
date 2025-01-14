#ifndef PIECE_H
#define PIECE_H

namespace chess {
    class Board;
    
    class Piece {
        public:
            virtual ~Piece() {}
            Piece(int r, int c, bool clr, int p, char s) : row(r), col(c), color(clr), points(p), symbol(s) {}

            int getRow() const { return row; }
            int getCol() const { return col; }
            bool getColor() const { return color; }
            int getPoints() const { return points; }
            char getSymbol() const { return symbol; }

            void setRow(int r) { row = r; }
            void setCol(int c) { col = c; }

            virtual void printPiece() = 0;
            virtual bool legalMove(Board &board, int row, int col) = 0;
        protected:
            int row, col;
            bool color;
            int points;
            char symbol; // for checks (to distinguish between Knight and Bishop)
    };
}

#endif