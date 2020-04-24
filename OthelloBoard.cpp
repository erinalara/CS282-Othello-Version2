#include "OthelloBoard.h"
using namespace std;


OthelloBoard::OthelloBoard() :
	mCurrentPlayer(Player::BLACK), mCurrentValue(0),
	mBoard({{
			{Player::EMPTY }, {Player::EMPTY}, {Player::EMPTY},
			{Player::EMPTY, Player::EMPTY, Player::EMPTY, Player::WHITE, Player::BLACK, Player::EMPTY, Player::EMPTY, Player::EMPTY},
			{Player::EMPTY, Player::EMPTY, Player::EMPTY, Player::BLACK, Player::WHITE, Player::EMPTY, Player::EMPTY, Player::EMPTY},
		}})
{
}


/*
Returns a vector with all possible moves on the current board state for
the current player. The moves should be ordered based first on row, then on
column. Example ordering: (0, 5) (0, 7) (1, 0) (2, 0) (2, 2) (7, 7)
You cannot use a sorting method to achieve this ordering.

If there are no legal moves for the current player, then a single "pass"
OthelloMove should be the only element of the returned vector.
*/
/*

vector<unique_ptr<OthelloMove>> OthelloBoard::GetPossibleMoves() const {
    
    vector<unique_ptr<OthelloMove>> list;
    
    for (int k = -1; k < 2; k++) {
        for (int i = -1; i < 2; i++) {

            int counter = 0, totalK = k, totalI = i;

            while ((mBoard[m->mPosition.GetRow() + totalK][m->mPosition.GetCol() + totalI] != mCurrentPlayer) & (mBoard[m->mPosition.GetRow() + totalK][m->mPosition.GetCol() + totalI] != Player::EMPTY)) {
                counter++;
                totalK += k;
                totalI += i;

            }
            if (mBoard[m->mPosition.GetRow() + totalK][m->mPosition.GetCol() + totalI] == mCurrentPlayer) {
                while (counter != 0) {
                    counter--;
                    totalK -= k;
                    totalI -= i;
                    mBoard[m->mPosition.GetRow() + totalK][m->mPosition.GetCol() + totalI] = mCurrentPlayer;
                }
            }
        }
    }

}
*/

/*
Applies a valid move to the board, updating the board state accordingly.
You may assume that this move is valid, and is consistent with the list
of possible moves returned by GetAllMoves. Takes ownership of this move
by placing it in the move history vector.
*/
void OthelloBoard::ApplyMove(unique_ptr<OthelloMove> m) {
    
    mBoard[m->mPosition.GetRow()][m->mPosition.GetCol()] = mCurrentPlayer;
    
    for (int k = -1; k < 2; k++) {
        for (int i = -1; i < 2; i++) {

            int counter = 0, totalK = k, totalI = i;

            while ((mBoard[m->mPosition.GetRow() + totalK][m->mPosition.GetCol() + totalI] != mCurrentPlayer) & (mBoard[m->mPosition.GetRow() + totalK][m->mPosition.GetCol() + totalI] != Player::EMPTY)) {
                counter++;
                totalK += k;
                totalI += i;

            }
            if (mBoard[m->mPosition.GetRow() + totalK][m->mPosition.GetCol() + totalI] == mCurrentPlayer) {
                while (counter != 0) {
                    counter--;
                    totalK -= k;
                    totalI -= i;
                    mBoard[m->mPosition.GetRow() + totalK][m->mPosition.GetCol() + totalI] = mCurrentPlayer;
                }
            }
        }
    }
}



