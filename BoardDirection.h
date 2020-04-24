//
// Created by Erina Lara on 3/12/20.
//

#include <array>
#pragma once

class BoardDirection {

private:
    char changeRow;
    char changeCol;

public:
    BoardDirection();
    BoardDirection(char changeR, char changeC);

    inline const char& GetRowChange() const { return changeRow; };
    inline const char& GetColChange() const { return changeCol; };

    static std::array<BoardDirection, 8> CARDINAL_DIRECTIONS;

};