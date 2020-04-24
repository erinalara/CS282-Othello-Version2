//
// Created by Erina Lara on 3/12/20.
//

#include "BoardDirection.h"
using namespace std;

BoardDirection::BoardDirection() : changeRow(0), changeCol(0) { }
BoardDirection::BoardDirection(char changeR, char changeC) : changeRow(changeR), changeCol(changeC) { }
array<BoardDirection, 8> BoardDirection::CARDINAL_DIRECTIONS = {
        BoardDirection(-1,-1),BoardDirection(-1,0),BoardDirection(-1,1),
        BoardDirection(0,-1),BoardDirection(0,1),BoardDirection(1,-1),
        BoardDirection(1,0),BoardDirection(1,1) };