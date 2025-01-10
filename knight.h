#ifndef KNIGHT_H
#define KNIGHT_H

namespace chess {
    class Knight : public Piece {
        public:
            Knight();
            void legalMoves();
        private:
            int points = 3;
    }
}

#endif