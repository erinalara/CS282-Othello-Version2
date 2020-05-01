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


unique_ptr<OthelloMove> OthelloView::ParseMove(const std::string& strFormat) {
    
    istringstream parse{ strFormat };
    char p1, comma, p2;
    int row, col;
    parse >> p1 >> row >> comma >> col >> p2;
    unique_ptr<OthelloMove> move = make_unique<OthelloMove>(BoardPosition(row, col));
    return move;


}



ostream& operator<< (std::ostream& lhs, const OthelloView& rhs) {
    rhs.PrintBoard(lhs);
    int m = (int) rhs.mOthelloBoard->GetCurrentPlayer();
    return lhs << "Player " << m << "'s turn.";
}


ostream& operator<<(std::ostream& lhs, const OthelloMove& rhs) {
    return lhs << string(rhs);
}

