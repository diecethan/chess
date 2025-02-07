#include <cstdio>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cctype>

#include "piece.h"
#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"

#include "board.h"

using namespace std;

namespace chess {
    Board::Board() : currColor(true), p1pts(0), p2pts(0){
        for (int row = 0; row < 8; row++) {
            vector<Piece*> pieces(8, nullptr);
            
            if (row == 0 || row == 7) {
                pieces[0] = (row == 0) ? new Rook(0, 0, true) : new Rook(7, 0, false);
                pieces[1] = (row == 0) ? new Knight(0, 1, true) : new Knight(7, 1, false);
                pieces[2] = (row == 0) ? new Bishop(0, 2, true) : new Bishop(7, 2, false);
                pieces[3] = (row == 0) ? new Queen(0, 3, true) : new Queen(7, 3, false);
                pieces[4] = (row == 0) ? new King(0, 4, true) : new King(7, 4, false);
                pieces[5] = (row == 0) ? new Bishop(0, 5, true) : new Bishop(7, 5, false);
                pieces[6] = (row == 0) ? new Knight(0, 6, true) : new Knight(7, 6, false);
                pieces[7] = (row == 0) ? new Rook(0, 7, true) : new Rook(7, 7, false);
            }
            else if (row == 1 || row == 6) {
                for (int col = 0; col < 8; col++) {
                    pieces[col] = (row == 1) ? new Pawn(row, col, true) : new Pawn(row, col, false);
                }
            }

            board.push_back(pieces);
        }

        whiteKing[0] = 0;
        whiteKing[1] = 4;
        blackKing[0] = 7;
        blackKing[1] = 4;
    }

    void Board::printBoard() const {
        cout << "  ";
        for (int col = 0; col < 8; col++) {
            cout << static_cast<char>(col + 97) << " ";
        }
        cout << endl;

        for (int row = 7; row >= 0; row--) {
            cout << row + 1 << " ";
            for (int col = 0; col < 8; col++) {
                if (board[row][col] != nullptr) {
                    board[row][col]->printPiece();
                    cout << " ";
                } else {
                    cout << "  ";
                }

            }
            cout << endl;
        }
    }

    bool Board::move(string src, string dst) {
        int srcRow = src[1] - 49;
        int srcCol = src[0] - 97;

        int dstRow = dst[1] - 49;
        int dstCol = dst[0] - 97;
        
        Piece* piece = getPiece(srcRow, srcCol);
        if (piece == nullptr || piece->getColor() != currColor) {
            return false;
        }

        if (piece->legalMove(*this, dstRow, dstCol)) {
            // En Passant updating and checking       
            if (!updatePieces.empty()) {
                for (int i = 0; i < updatePieces.size(); i++) {
                    static_cast<Pawn*>(updatePieces[i])->setPassant(false);
                }
                updatePieces.clear();
            }

            if (piece->getPoints() == 1) {
                if (static_cast<Pawn*>(piece)->getPassant()) {
                    updatePieces.push_back(piece);
                }

                if (board[dstRow][dstCol] == nullptr &&  srcCol != dstCol) {
                    if (currColor) {
                        delete board[dstRow - 1][dstCol];
                        board[dstRow - 1][dstCol] = nullptr;
                    } else {
                        delete board[dstRow + 1][dstCol];
                        board[dstRow + 1][dstCol] = nullptr;
                    }
                }
            }

            // Basic updating and checking
            if (board[dstRow][dstCol] != nullptr) {
                if (currColor) {
                    p1pts += board[dstRow][dstCol]->getPoints();
                } else {
                    p2pts += board[dstRow][dstCol]->getPoints();
                }
                delete board[dstRow][dstCol];
            }

            // castling and King Position updating for theoreticalMove()
            if (piece->getPoints() > 1) {
                piece->setRow(dstRow);
                piece->setCol(dstCol);

                board[dstRow][dstCol] = piece;
                board[srcRow][srcCol] = nullptr;
            } 
            else if (piece->getPoints() == 1) {
                if (dstRow == 0 || dstRow == 7) {
                    delete piece;
                    board[srcRow][srcCol] = nullptr;
                    
                    char newPiece;
                    
                    while (newPiece != 'Q' && newPiece != 'R' && newPiece != 'N' && newPiece != 'B') {
                        cout << "What piece would you like to promote to (Q, R, N, B)? ";
                        cin >> newPiece;
                        cout << endl;
                    }

                    switch (newPiece) {
                        case 'Q':
                            board[dstRow][dstCol] = new Queen(dstRow, dstCol, currColor);
                            break;
                        case 'R':
                            board[dstRow][dstCol] = new Rook(dstRow, dstCol, currColor);
                            break;
                        case 'N':
                            board[dstRow][dstCol] = new Knight(dstRow, dstCol, currColor);
                            break;
                        case 'B':
                            board[dstRow][dstCol] = new Bishop(dstRow, dstCol, currColor);
                            break;
                    }

                } else {
                    piece->setRow(dstRow);
                    piece->setCol(dstCol);

                    board[dstRow][dstCol] = piece;
                    board[srcRow][srcCol] = nullptr;
                }
            } else {
                // castling movement
                if (abs(srcCol - dstCol) > 1) {
                    Rook* rook;
                    
                    if (srcCol > dstCol) {
                        rook = static_cast<Rook*>(getPiece(dstRow, dstCol - 2));
                        
                        piece->setCol(dstCol);
                        rook->setCol(dstCol + 1);

                        board[dstRow][dstCol] = piece;
                        board[dstRow][dstCol + 1] = rook;
                        
                        board[srcRow][srcCol] = nullptr;
                        board[dstRow][dstCol - 2] = nullptr;
                    } else {
                        rook = static_cast<Rook*>(getPiece(dstRow, dstCol + 1));
                        
                        piece->setCol(dstCol);
                        rook->setCol(dstCol - 1);

                        board[dstRow][dstCol] = piece;
                        board[dstRow][dstCol - 1] = rook;
                        
                        board[srcRow][srcCol] = nullptr;
                        board[dstRow][dstCol + 1] = nullptr;

                    }
                } else {
                    piece->setRow(dstRow);
                    piece->setCol(dstCol);

                    board[dstRow][dstCol] = piece;
                    board[srcRow][srcCol] = nullptr;
                }

                if (currColor) {
                    whiteKing[0] = dstRow;
                    whiteKing[1] = dstCol;
                } else {
                    blackKing[0] = dstRow;
                    blackKing[1] = dstCol;
                }
            }

            currColor = !currColor;
            return true;
        }

        return false;
    }

    bool Board::theoreticalMove(Piece* piece, int srcRow, int srcCol, int dstRow, int dstCol, bool castling) {
        bool result;
        if (!castling) {
            Piece* tempPiece = (board[dstRow][dstCol] == nullptr) ? nullptr : board[dstRow][dstCol];

            board[dstRow][dstCol] = piece;
            board[srcRow][srcCol] = nullptr;

            if (currColor) {
                if (piece->getPoints() == 0) {
                    piece->setRow(dstRow);
                    piece->setCol(dstCol);

                    result = static_cast<King*>(piece)->inCheck(*this);

                    piece->setRow(srcRow);
                    piece->setCol(srcCol);
                } else {
                    result = static_cast<King*>(getPiece(whiteKing[0], whiteKing[1]))->inCheck(*this);
                }
            } else {
                if (piece->getPoints() == 0) {
                    piece->setRow(dstRow);
                    piece->setCol(dstCol);

                    result = static_cast<King*>(piece)->inCheck(*this);

                    piece->setRow(srcRow);
                    piece->setCol(srcCol);
                } else {
                    result = static_cast<King*>(getPiece(blackKing[0], blackKing[1]))->inCheck(*this);
                }
            }

            board[srcRow][srcCol] = piece;
            board[dstRow][dstCol] = tempPiece;

            return result;
        } else {
            Rook* rook;
            
            if (srcCol > dstCol) {
                rook = static_cast<Rook*>(getPiece(dstRow, dstCol - 2));
                
                piece->setCol(dstCol);

                board[dstRow][dstCol] = piece;
                board[dstRow][dstCol + 1] = rook;
                
                board[srcRow][srcCol] = nullptr;
                board[dstRow][dstCol - 2] = nullptr;

                result = static_cast<King*>(piece)->inCheck(*this);

                piece->setCol(srcCol);

                board[dstRow][dstCol] = nullptr;
                board[dstRow][dstCol + 1] = nullptr;
                
                board[srcRow][srcCol] = piece;
                board[dstRow][dstCol - 2] = rook;
            } else {
                rook = static_cast<Rook*>(getPiece(dstRow, dstCol + 1));
                
                piece->setCol(dstCol);

                board[dstRow][dstCol] = piece;
                board[dstRow][dstCol - 1] = rook;
                
                board[srcRow][srcCol] = nullptr;
                board[dstRow][dstCol + 1] = nullptr;
                
                result = static_cast<King*>(piece)->inCheck(*this);

                piece->setCol(srcCol);

                board[dstRow][dstCol] = nullptr;
                board[dstRow][dstCol - 1] = nullptr;
                
                board[srcRow][srcCol] = piece;
                board[dstRow][dstCol + 1] = rook;
            }

            return result;
        }
    }

    bool Board::checkmate() {
        King* king;
        if (currColor) {
            king = static_cast<King*>(getPiece(whiteKing[0], whiteKing[1]));
        } else {
            king = static_cast<King*>(getPiece(blackKing[0], blackKing[1]));
        }

        if (!king->inCheck(*this)) {
            return false;
        }

        int kingDirs[8][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };
        for (auto &dir : kingDirs) {
            int checkRow = king->getRow() + dir[0];
            int checkCol = king->getCol() + dir[1];

            if (checkRow >= 0 && checkRow < 8 && checkCol >= 0 && checkCol < 8) {
                if (king->legalMove(*this, checkRow, checkCol)) {
                    if (!theoreticalMove(king, king->getRow(), king->getCol(), checkRow, checkCol, false)) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
}
