#include "OthelloMove.h"
#include <sstream>
#include <iostream>
using namespace std;

bool OthelloMove::operator==(const OthelloMove& rhs) {
	return this->mPosition == rhs.mPosition;
}



OthelloMove::operator std::string() const {
	ostringstream os;
	os << "(" << int(mPosition.GetRow()) << ", " << int(mPosition.GetCol()) << ")";
	return os.str();
}


