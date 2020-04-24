#include "OthelloMove.h"
#include <sstream>
#include <iostream>
using namespace std;

bool OthelloMove::operator==(const OthelloMove& rhs) {
	return this->mPosition == rhs.mPosition;
}


/*
Converts the OthelloMove into a string representation, one that could be
used correctly with operator=(string).
*/
OthelloMove::operator std::string() const {
	ostringstream os;
	os << "(" << mPosition.GetRow() << ", " << mPosition.GetCol() << ")";
	return os.str();
}


