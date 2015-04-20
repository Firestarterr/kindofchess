using namespace std;

#include "hw2.h"

bool isOutOfBoard(Column clmn, int row) {
    if (clmn == OUT) {
        return true;
    }
    return row < 1 || row > 8;
}

// throws OutofBoard
bool Piece::isOccupied(Color clr, Column clmn, int row) {
    if (!isOutOfBoard(clmn, row)) {
        Piece *p = board[row][clmn];
        if (p != NULL) {
            if (p->color == clr) {
                return true;
            } else {
                cout << "captured: " << p->draw() << " at " << ctoname[clmn] << row << endl;
                return false;
            }
        } else {
            return false;
        }
    } else {
        throw new OutofBoard();
    }
}

// throws OutofBoard , Occupied
Piece::Piece(Color cl, Column co, int i) {
    if (isOutOfBoard(co, i)) {
        throw new OutofBoard();
    }
    if (board[i][co] == NULL) {
        color = cl;
        x = co;
        y = i;
        board[y][x] = this;
    } else {
        throw new Occupied();
    }
}

// throws OutofBoard , CannotMove , EmptyCell
void Piece::move(Column clmn, int row) {
    if (isOutOfBoard(clmn, row)) {
        throw new OutofBoard();
    }
    try {
        if (canmove(clmn, row) != 0) {
            if (isOccupied(this->color, clmn, row)) {
                cout << "occupied:" << clmn << row;
                throw new CannotMove();
            } else {
                board[y][x] = NULL;
                y = row;
                x = clmn;
                board[row][clmn] = this;
            }
        }
    } catch (Exception e) {
        throw new CannotMove();
    }
}

// throws EmptyCell
Piece *Piece::getpiece(Column clmn, int row) {
    if (board[row][clmn] == NULL) {
        throw new EmptyCell();
    }
    return board[row][clmn];
}
