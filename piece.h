#ifndef PIECE_H
#define PIECE_H

namespace chess {
    class Piece {
        public:
            virtual void legalMoves() = 0;
            virtual void move() = 0;
            int player;
    };
}

#endif