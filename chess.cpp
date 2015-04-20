#include "hw2.h"
#include "cstring"
#include "cmath"

class Knight : public Piece {


public:
    Knight(Color const &clr, Column const &clmn, int row) : Piece(clr, clmn, row) {
        if (clr == BLACK) {
            piecename = "* N *";
        } else {
            piecename = ". N .";
        }
    }

    virtual ~Knight() { }

private:
    virtual int canmove(Column column, int i) const;

    virtual const char *draw() const;
};

class Bishop : public Piece {

public:
    Bishop(Color const &clr, Column const &clmn, int row) : Piece(clr, clmn, row) {
        if (clr == BLACK) {
            piecename = "* B *";
        } else {
            piecename = ". B .";
        }
    }

    virtual ~Bishop() { }

private:
    virtual int canmove(Column column, int i) const;

    virtual const char *draw() const;
};

class Rook : public Piece {

public:
    Rook(Color const &clr, Column const &clmn, int row) : Piece(clr, clmn, row) {
        if (clr == BLACK) {
            piecename = "* R *";
        } else {
            piecename = ". R .";
        }
    }

    virtual ~Rook() { }

private:
    virtual int canmove(Column column, int i) const;

    virtual const char *draw() const;
};

class Queen : public Piece {

public:
    Queen(Color const &clr, Column const &clmn, int row) : Piece(clr, clmn, row) {
        if (clr == BLACK) {
            piecename = "* Q *";
        } else {
            piecename = ". Q .";
        }
    }

    virtual ~Queen() { }

private:
    virtual int canmove(Column column, int i) const;

    virtual const char *draw() const;
};

class King : public Piece {

public:
    King(Color const &clr, Column const &clmn, int row) : Piece(clr, clmn, row) {
        if (clr == BLACK) {
            piecename = "* K *";
        } else {
            piecename = ". K .";
        }
    }

    virtual ~King() { }

private:
    virtual int canmove(Column column, int i) const;

    virtual const char *draw() const;
};

class Pawn : public Piece {

public:
    Pawn(Color const &clr, Column const &clmn, int row) : Piece(clr, clmn, row) {
        if (clr == BLACK) {
            piecename = "* P *";
        } else {
            piecename = ". P .";
        }
    }

    virtual ~Pawn() { }


    virtual void move(Column clmn, int row) override;

private:
    bool isFirstMove = true;

    virtual int canmove(Column column, int i) const;

    virtual const char *draw() const;

    static bool isOccupied(Color clr, Column clmn, int row);

};

Piece *create(const char *piecename, Color clr, Column clmn, int row) {
    if (row < 1 || row > 8 || clmn < A || clmn > H) {
        throw OutofBoard();

    }
    else {
        if (strcmp(piecename, "pawn") == 0) {
            Pawn *created = new Pawn(clr, clmn, row);
            return created;
        }
        else if (strcmp(piecename, "knight") == 0) {
            Knight *created = new Knight(clr, clmn, row);
            return created;
        }
        else if (strcmp(piecename, "bishop") == 0) {
            Bishop *created = new Bishop(clr, clmn, row);
            return created;
        }
        else if (strcmp(piecename, "rook") == 0) {
            Rook *created = new Rook(clr, clmn, row);
            return created;
        }
        else if (strcmp(piecename, "queen") == 0) {
            Queen *created = new Queen(clr, clmn, row);
            return created;
        }
        else if (strcmp(piecename, "king") == 0) {
            King *created = new King(clr, clmn, row);
            return created;
        }
        else return NULL;
    }
}

int Knight::canmove(Column column, int i) const {
    //TODO impl
    return 1;
}

const char *Knight::draw() const {
    return piecename;
}

int Bishop::canmove(Column column, int i) const {
    if (abs(column - x) == abs(i - y)) {
        return 1;
    } else {
        return 0;
    }
}

const char *Bishop::draw() const {
    return piecename;
}

int Rook::canmove(Column column, int i) const {
    if (column == x || i == y) {
        return 1;
    } else {
        return 0;
    }
}

const char *Rook::draw() const {
    return piecename;
}

int Queen::canmove(Column column, int i) const {
    if (abs(column - x) == abs(i - y)) {
        return 1;
    } else if (column == x || i == y) {
        return 1;
    } else {
        return 0;
    }
}

const char *Queen::draw() const {
    return piecename;
}

int King::canmove(Column column, int i) const {
    if (abs(column - x) < 1 && abs(i - y) < 1) {
        return 1;
    } else {
        return 0;
    }
}

const char *King::draw() const {
    return piecename;
}

int Pawn::canmove(Column column, int i) const {
    int maxDistance = isFirstMove ? 2 : 1;
    if (column == x) {
        int dist;
        if (color == WHITE) {
            dist = i - y;
        } else {
            dist = y - i;
        }
        cout << dist << endl;
        cout << maxDistance << endl;
        if (0 < dist && dist <= maxDistance) {
            return 1;
        } else {
            throw new CannotMove();
        }
    } else {
        //TODO yeme impl
    }
    return 0;
}

const char *Pawn::draw() const {
    return piecename;
}

void Pawn::move(Column clmn, int row) {
    Piece::move(clmn, row);
    isFirstMove = false;
}

bool Pawn::isOccupied(Color clr, Column clmn, int row) {
    //TODO gidisi farkli, yiyisi farkli oldugu icin farkli bir isoccupied yazilmali
    Piece::isOccupied(clr, clmn, row);
}
