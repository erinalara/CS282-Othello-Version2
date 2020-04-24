//
// Created by Erina Lara on 3/6/20.
//
#include <string>
#include <vector>
#include "BoardDirection.h"
#pragma once

class BoardPosition {

private:
    char mRow;
    char mCol;

public:
    BoardPosition();
    BoardPosition(char r, char c);

    inline const char& GetRow() const { return mRow; };
    inline const char& GetCol() const { return mCol; };

    operator std::string() const;
    friend std::istream& operator>>(std::istream& lhs, BoardPosition& rhs);
    bool operator==(BoardPosition rhs) const;
    bool operator<(BoardPosition rhs) const;

    bool InBounds(int boardSize);
    bool InBounds(int rows, int columns);
    static std::vector<BoardPosition> GetRectangularPositions(int rows, int columns);

    BoardPosition operator+(BoardDirection dir);
};

std::ostream& operator<<(std::ostream& lhs, BoardPosition rhs);