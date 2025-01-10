#ifndef BOARD_H
#define BOARD_H

#include <vector>

namespace chess {
    class Board {
        public:
            Board();
            void print();
        private:
            vector<vector> board;
    };
}

#endif