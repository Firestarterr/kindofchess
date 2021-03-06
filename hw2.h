#ifndef CHESSOOPODEV2_HW2_H
#define CHESSOOPODEV2_HW2_H

# include <iostream>

using namespace std;

class Exception {
    const char *mess;
public:
    Exception(const char *m) { mess = m; }

    void output() { cerr << mess << "\n"; }
};

// A piece with invalid color value is tried to be constructed
class InvalidColor : public Exception {
public:
    InvalidColor() : Exception(" Invalid piece color ") { }
};

// A move outside of the board is attempted
class OutofBoard : public Exception {
public:
    OutofBoard() : Exception(" Out of the Board ") { }
};

// A piece is tried to be placed on an already occupied cell
class Occupied : public Exception {
public:
    Occupied() : Exception(" Location is occupied ") { }
};

// An invalid move is targeted for the piece kind
class CannotMove : public Exception {
public:
    CannotMove() : Exception(" Cannot move there ") { }
};

// A piece is expected on the cell but , the cell is empty
class EmptyCell : public Exception {
public:
    EmptyCell() : Exception("The cell is empty , no piece there ") { }
};

enum Color {
    BLACK, WHITE
};
enum Column {
    A, B, C, D, E, F, G, H, OUT
};
const char ctoname[] = "ABCDEFGH "; // convert Column type to character
// for printing . ctoname [A] is �A�
const char coltoname[][10] = {"BLACK", "WHITE"}; // convert Color type to color
// name . coltoname [ BLACK ] is " BLACK "
// macro to convert character input into Column name nametoc (�a �) is A ,
// nametoc (�H �) is H.
#define nametoc(a)(( 'a'<= a && a<='h')?( Column ) (a-'a'):('A' <= a && a <= 'H')?(Column) (a - 'A'):OUT)

// Base abstract class .
class Piece {

protected:
    const char *piecename;
    static Piece *board[9][OUT]; // board is a class member variable
    Color color; // BLACK or WHITE
    Column x; // A to H
    int y; // 1 to 8. 8 is top , 1 is bottom
    // each piece kind (Pawn , Knight , Bishop , Rook , Queen , King ) decides on its own f
    virtual int canmove(Column, int) const = 0;

    // each piece returns a string denoting itself (P, N, B, R, Q, K)
    virtual const char *draw() const = 0;

public:
    // throws OutofBoard , Occupied
    Piece(Color clr, Column clmn, int row);

    Color getcolor() const { return color; }

    virtual // throws OutofBoard , CannotMove
    void move(Column clmn, int row);

    // throws EmptyCell
    static Piece *getpiece(Column clmn, int row);

    // throws OutofBoard
    static bool isOccupied(Color clr, Column clmn, int row);

    // draw the current state of the board , uses draw functions from pieces
    static void drawboard() {
        const char empty[] =
                "|       |       |       |       |       |       |       |       |\n";
        const char line[] =
                "+-------+-------+-------+-------+-------+-------+-------+-------+\n";
        cout << line << empty;
        for (int r = 8; r > 0; r--) {
            for (int c = A; c <= H; ++c)
                if (board[r][c] == NULL)
                    cout << "|       ";
                else
                    cout << "| " << board[r][c]->draw() << " ";
            cout << "|\n" << empty << line;

            if (r > 1)
                cout << empty;
        }
    }

};

// initialize cells to be empty
// create a piece depending on the name given in first argument
// pawn , knight , bishop , rook , queen and king
// returns NULL if no such piece is defined
extern Piece *create(const char *piecename, Color clr, Column clmn, int row);


#endif //CHESSOOPODEV2_HW2_H
