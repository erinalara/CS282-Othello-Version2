//
// Created by Erina Lara on 3/6/20.
//
#include "BoardPosition.h"
#include <sstream>


using namespace std;

BoardPosition::BoardPosition() : mRow(0), mCol(0) { }

BoardPosition::BoardPosition(char r, char c) : mRow(r), mCol(c) { }

BoardPosition::operator std::string() const {
    ostringstream os;
    os << "(" << int(mRow) << "," << int(mCol) << ")";
    return os.str();
}

ostream& operator<<(std::ostream& lhs, BoardPosition rhs) {
    lhs << string(rhs);
    return lhs;
}

istream& operator>>(std::istream& lhs, BoardPosition& rhs) {
    string f = "(,)";
    int row, col;
    lhs >> f[0] >> row >> f[1] >> col >> f[2];
    rhs = BoardPosition(row, col);
    return lhs;
}

bool BoardPosition::operator==(BoardPosition rhs) const {
    return (static_cast<int>(mRow) == static_cast<int>(rhs.mRow) &&
        static_cast<int>(mCol) == static_cast<int>(rhs.mCol));
}

bool BoardPosition::operator<(BoardPosition rhs) const {
    if (static_cast<int>(mRow) == static_cast<int>(rhs.mRow)) {
        return static_cast<int>(mCol) < static_cast<int>(rhs.mCol);
    }
    else {
        return static_cast<int>(mRow) < static_cast<int>(rhs.mRow);
    }
}

bool BoardPosition::InBounds(int boardSize) {
    return ((mRow >= 0) && (mRow < (boardSize - 1))) && ((mCol >= 0) && (mCol < (boardSize - 1)));

}

bool BoardPosition::InBounds(int rows, int columns) {
    return (mRow >= 0 && mRow < rows) && (mCol >= 0 && (mCol < columns));
}

vector<BoardPosition> BoardPosition::GetRectangularPositions(int rows, int columns) {

    vector<BoardPosition> positions;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            positions.push_back(BoardPosition(i, j));
        }
    }
    return positions;
}

BoardPosition BoardPosition::operator+(BoardDirection dir) {
    mRow += dir.GetRowChange();
    mCol += dir.GetColChange();

    return BoardPosition(mRow, mCol);
}
