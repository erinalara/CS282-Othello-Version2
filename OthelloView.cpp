#include "OthelloView.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

void OthelloView::PrintBoard(std::ostream& s) const {
    cout << "- " << "0 " << "1 " << "2 " << "3 " << "4 " << "5 " << "6 " << "7 " << endl;

    for (int r = 0; r < mOthelloBoard->BOARD_SIZE; r++) {
        cout << r << " ";
        for (int c = 0; c < mOthelloBoard->BOARD_SIZE; c++) {
            if ((int) mOthelloBoard->mBoard[r][c] == 1) {
                cout << "B ";
            }
            else if ((int) mOthelloBoard->mBoard[r][c] == -1) {
                cout << "W ";
            }
            else {
                cout << ". ";
            }
        }
        cout << endl;
    }
}

// Creates and returns ownership of an OthelloMove object by parsing a string
// of the format (r, c) and constructing a corresponding Move object. Yields
// ownership of the created Move.
// You can assume that the string contains a valid move format.

unique_ptr<OthelloMove> OthelloView::ParseMove(const std::string& strFormat) {
    
    istringstream parse{ strFormat };
    char p1, comma, p2;
    int row, col;
    parse >> p1 >> row >> comma >> col >> p2;
    unique_ptr<OthelloMove> move = make_unique<OthelloMove>(BoardPosition(row, col));
    return move;
    /*
    int row = strFormat[1];
    int col = strFormat[4];
    unique_ptr<OthelloMove> move = make_unique<OthelloMove>(BoardPosition(row, col));
    //mOthelloBoard->mBoard[row][col] = move((int)temp);
    //return temp;
    //return make_unique<OthelloMove>(BoardPosition(row, col));
    //return make_unique<OthelloMove> (mOthelloBoard->mBoard[row][col]);
    return move;
    */


}


// Outputting a View object causes it to print its owned Board to the output stream.
// The printed output should include the board itself, and the current player.
// LINE LIMIT: 3 lines.
ostream& operator<< (std::ostream& lhs, const OthelloView& rhs) {
    rhs.PrintBoard(lhs);
    int m = (int) rhs.mOthelloBoard->GetCurrentPlayer();
    return lhs << m;
}

// It doesn't belong to the OthelloView class, but we still consider this operator
// to be part of the "view". This operator prints a Move by printing its position.
// Reminder: OthelloMove has operator std::string.
// LINE LIMIT: 1 line.
ostream& operator<<(std::ostream& lhs, const OthelloMove& rhs) {
    return lhs << string(rhs);
}

