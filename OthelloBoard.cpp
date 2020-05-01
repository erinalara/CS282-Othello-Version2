#include "OthelloBoard.h"
#include <iostream>
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


vector<unique_ptr<OthelloMove>> OthelloBoard::GetPossibleMoves() const {

    vector<unique_ptr<OthelloMove>> possible;

    for (int r = 0; r < BOARD_SIZE; r++) {
        for (int c = 0; c < BOARD_SIZE; c++) {

            if (mBoard[r][c] == Player::EMPTY) {

                for (int i = 0; i < int(BoardDirection::CARDINAL_DIRECTIONS.size()); i++) {

                    int counter = 0, totalK = int(BoardDirection::CARDINAL_DIRECTIONS[i].GetRowChange()), totalI = int(BoardDirection::CARDINAL_DIRECTIONS[i].GetColChange());             
                    BoardPosition move = BoardPosition(r, c);

                    while ((InBounds(BoardPosition(r + totalK, c + totalI)) && (mBoard[r + totalK][c + totalI] == Player(int(GetCurrentPlayer()) * -1)))) {
                        counter++;
                        totalK += BoardDirection::CARDINAL_DIRECTIONS[i].GetRowChange();
                        totalI += BoardDirection::CARDINAL_DIRECTIONS[i].GetColChange();

                    }

                    if ((InBounds(BoardPosition(r + totalK, c + totalI)) && (mBoard[r + totalK][c + totalI] == GetCurrentPlayer()) & (counter != 0))) {
                        possible.push_back(make_unique<OthelloMove>(OthelloMove(move)));
                        break;
                    }
                    else {
                        continue;
                    }

                }
            }
        }
    }

    return possible;

}




void OthelloBoard::ApplyMove(unique_ptr<OthelloMove> m) {

    if (!m->IsPass()) {

        mBoard[m->mPosition.GetRow()][m->mPosition.GetCol()] = mCurrentPlayer;

        for (int i = 0; i < int(BoardDirection::CARDINAL_DIRECTIONS.size()); i++) {
            int c = 0, k = BoardDirection::CARDINAL_DIRECTIONS[i].GetRowChange(), j = BoardDirection::CARDINAL_DIRECTIONS[i].GetColChange();


            while ((InBounds(BoardPosition(m->mPosition.GetRow() + k, m->mPosition.GetCol() + j))) && 
                (PositionIsEnemy(BoardPosition(m->mPosition.GetRow() + k, m->mPosition.GetCol() + j), mCurrentPlayer))) {
                c++;
                k += int(BoardDirection::CARDINAL_DIRECTIONS[i].GetRowChange());
                j += int(BoardDirection::CARDINAL_DIRECTIONS[i].GetColChange());

            }

            if ((InBounds(BoardPosition(m->mPosition.GetRow() + k, m->mPosition.GetCol() + j))) && 
                (mBoard[m->mPosition.GetRow() + k][m->mPosition.GetCol() + j] == mCurrentPlayer)) {
                m->AddFlipSet(OthelloMove::FlipSet(c, BoardDirection(BoardDirection::CARDINAL_DIRECTIONS[i].GetRowChange(), BoardDirection::CARDINAL_DIRECTIONS[i].GetColChange())));

                while (c != 0) {
                    c--;
                    k -= int(BoardDirection::CARDINAL_DIRECTIONS[i].GetRowChange());
                    j -= int(BoardDirection::CARDINAL_DIRECTIONS[i].GetColChange());

                    mCurrentPlayer == Player::BLACK ? mCurrentValue += 2 : mCurrentValue -= 2;
                    mBoard[m->mPosition.GetRow() + k][m->mPosition.GetCol() + j] = mCurrentPlayer;
                }
            }

        }
    }
    mHistory.push_back(move(m));    
    mCurrentPlayer = Player(int(mCurrentPlayer) * -1);
}


void OthelloBoard::UndoLastMove() {

    auto& m = mHistory.back();

    mBoard[m->mPosition.GetRow()][m->mPosition.GetCol()] = Player::EMPTY;


    for (int i = 0; i < m->mFlips.size(); i++) {

        int rowCh = m->mFlips[i].mDirection.GetRowChange(), colCh = m->mFlips[i].mDirection.GetColChange();


        while ((InBounds(BoardPosition(m->mPosition.GetRow() -rowCh, m->mPosition.GetCol() - colCh))) &&
            (!PositionIsEnemy(BoardPosition(m->mPosition.GetRow() -rowCh, m->mPosition.GetCol() - colCh), mCurrentPlayer)) &&
            (m->mFlips[i].mFlipCount != 0)) {

            mBoard[m->mPosition.GetRow() + rowCh][m->mPosition.GetCol() + colCh] = mCurrentPlayer;
            m->mFlips[i].mFlipCount -= 1;
            rowCh += int(m->mFlips[i].mDirection.GetRowChange());
            colCh += int(m->mFlips[i].mDirection.GetRowChange());

            mCurrentPlayer == Player::BLACK ? mCurrentValue += 2 : mCurrentValue -= 2;


        }
    }

    mCurrentPlayer = Player(int(mCurrentPlayer) * -1);
    mHistory.pop_back();


}


bool OthelloBoard::IsFinished() {
    
    auto& history = GetMoveHistory();
    if (history.size() != 0) {
        for (int i = 0; i < history.size() - 1; i++) {
            if (history[i]->IsPass() && history[i + 1]->IsPass()) {
                return true;
            }
        }
    }

    return false;
    
}
