#include "OthelloBoard.h"
#include "OthelloView.h"
#include "OthelloMove.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <memory>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
	// Initialization
	auto board = std::make_shared<OthelloBoard>(); // the state of the game board
	OthelloView v(board); // a View for outputting the board via operator<<
	string userInput, space; // a string to hold the user's command choice


	/*
	// Start with this DEBUGGING CODE to make sure your basic OthelloMove and 
	// OthelloBoard classes work, then remove it when you are ready to work
	// on the real main.
	cout << "Initial board:" << endl;
	cout << v << endl;
	unique_ptr<OthelloMove> m{ v.ParseMove("(3, 2)") };
	cout << "Applying the move " << *m << endl;
	board->ApplyMove(std::move(m));
	cout << endl << v << endl; // should show a changed board.

	m = v.ParseMove("(4, 2)");
	cout << "Applying the move " << *m << endl;
	board->ApplyMove(std::move(m));
	cout << endl << v << endl;

	m = v.ParseMove("(5, 2)");
	cout << "Applying the move " << *m << endl;
	board->ApplyMove(std::move(m));
	cout << endl << v << endl;

	// END OF DEBUGGING CODE
	*/
	
	// Main loop
	do {
		// Print the game board using the OthelloView object
		cout << v << endl;
	   // Print all possible moves
		vector<unique_ptr<OthelloMove>> list = board->GetPossibleMoves();
		cout << "Possible moves: " << endl;
		if (list.size() != 0) {
			for (auto& pos : list) {
				cout << *pos << " ";
			}
		}
		else {
			cout << "Possible moves: " << endl << "pass" << endl;
		}
		
	   // Ask to input a command
		cout << endl << "Enter a command: " << endl;
		getline(cin, userInput);
		bool valid = false;


	   // Command loop:
		while (valid == false) {

			// move (r,c)
			if (userInput.substr(0, 4) == "move" || userInput.substr(0, 4) == "pass") {

				unique_ptr<OthelloMove> m;

				if (userInput.substr(0, 4) == "move") {
					
					m = { v.ParseMove(userInput.substr(5)) };

					int count = 0;
					for (int i = 0; i < list.size(); i++) {
						if ((*m == (*list[i])) == false) {
							count++;
						}
					}

					if (count == list.size()) {
						cout << "Not a valid move." << endl;
						break;
					}
					else {
						cout << endl << "Applying the move " << *m << endl;
						board->ApplyMove(move(m));
						valid = true;
					}

					
				}
				
				else {
					m = make_unique<OthelloMove>(OthelloMove(BoardPosition(-1, -1)));
					if (board->IsFinished()) {
						break;
					}

					cout << endl << "Applying the move " << *m << endl;
					board->ApplyMove(move(m));
					valid = true;
				}

			}

			// undo n
			else if (userInput.substr(0, 4) == "undo") { 
				cout << "Debug output: undo" << endl;
				istringstream parse{ userInput.substr(5) };
				int lim;
				parse >> lim;
				for (int i = 0; i < lim; i++) {
					board->UndoLastMove();
				}
				
				valid = true;
			}


			else {
				// showValue
				if (userInput.substr(0) == "showValue") {
					cout << "Debug output: you entered: showValue" << endl;
					cout << board->GetValue() << endl;

				}

				// showHistory
				else if (userInput.substr(0) == "showHistory") {
					
					auto& history = board->GetMoveHistory();
					if (history.size() != 0) {
						for (auto itr = history.rbegin(); itr != history.rend(); itr++) {
							cout << "Player " << int(board->GetCurrentPlayer()) << ": " << *(*itr) << endl;
						}
					}
					else {
						cout << "No history." << endl;
					}
				}

				// quit
				else if (userInput.substr(0) == "quit") {
					userInput == "quit";
					break;
				}

				cout << endl << "Enter a command: " << endl;
				getline(cin, userInput);
			}

		}
	} while ((board->IsFinished() == false) && (userInput != "quit")); // you may want to change the condition

	if (board->GetValue() > 0) {
		cout << "Player 1 (Black) has won!" << endl;
	}
	else if (board->GetValue() < 0) {
		cout << "Player 2 (White) has won!" << endl;
	}
	else {
		cout << "A tie!" << endl;
	}
}
