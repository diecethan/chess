#include <iostream>
#include "piece.h"
#include "pawn.h"
#include "board.h"

using namespace std;

namespace chess {
    bool Pawn::legalMove(Board &board, int row, int col) {
        // source = destination
        if (getRow() == row && getCol() == col) {
            return false;
        }

        // Ensure the Pawn does not move more than one from starting row
        if (abs(getCol() - col) > 1) {
            return false;
        }

        // Ensure the Pawn moved one forward (or two if first movement)
        Piece* pieceAtDst, *pieceInFront, *leftPiece, *rightPiece;
        if (getColor()) {
            pieceAtDst = board.getPiece(row, col);
            pieceInFront = board.getPiece(getRow() + 1, getCol());
            leftPiece = board.getPiece(getRow(), getCol() - 1);
            rightPiece = board.getPiece(getRow(), getCol() + 1);

            if (hasMoved) {
                if (getRow() + 1 != row) {
                    return false;
                }
            } else {
                if (getRow() + 2 < row) {
                    return false;
                }

                if (getRow() + 2 == row && getCol() != col) {
                    return false;
                }
            }
        } else {
            pieceAtDst = board.getPiece(row, col);
            pieceInFront = board.getPiece(getRow() - 1, getCol());
            leftPiece = board.getPiece(getRow(), getCol() - 1);
            rightPiece = board.getPiece(getRow(), getCol() + 1);

            if (hasMoved) {
                if (getRow() - 1 != row) {
                    return false;
                }
            } else {
                if (getRow() - 2 > row) {
                    return false;
                }

                if (getRow() - 2 == row && getCol() != col) {
                    return false;
                }
            }
        }

        if (getCol() != col) {
            if (pieceAtDst != nullptr && pieceAtDst->getColor() == getColor()) {
                return false;
            }

            if (pieceAtDst == nullptr) {
                if (col > getCol()) {
                    if (rightPiece == nullptr) {
                        return false;
                    }

                    if (rightPiece->getPoints() != 1) {
                        return false;
                    }

                    if (!static_cast<Pawn*>(rightPiece)->getPassant()) {
                        return false;
                    }
                } else {
                    if (leftPiece == nullptr) {
                        return false;
                    }

                    if (leftPiece->getPoints() != 1) {
                        return false;
                    }

                    if (!static_cast<Pawn*>(leftPiece)->getPassant()) {
                        return false;
                    }
                }
            }
        } else {
            if (pieceInFront != nullptr) {
                return false;
            }
        }

        // Checks that this move does not reveal a discovered check
        if (board.theoreticalMove(this, getRow(), getCol(), row, col, false)) {
            return false;
        }

        if (abs(getRow() - row) == 2) { setPassant(true); }
        hasMoved = true;
        return true;
    }

    void Pawn::printPiece() {
        if (getColor()) {
			cout << "♟";
        } else {
            cout << "♙";
        }
	}
}