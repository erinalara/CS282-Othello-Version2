#include "OthelloBoard.h"
#include "OthelloView.h"
#include "OthelloMove.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <memory>

using namespace std;

int main_(int argc, char* argv[]) {
	// Initialization
	auto board = std::make_shared<OthelloBoard>(); // the state of the game board
	OthelloView v(board); // a View for outputting the board via operator<<
	string userInput; // a string to hold the user's command choice



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

	// Main loop
	do {
		// Print the game board using the OthelloView object

	   // Print all possible moves

	   // Ask to input a command

	   // Command loop:
		  // move (r,c)
		  // undo n
		  // showValue
		  // showHistory
		  // quit

	} while (true); // you may want to change the condition
	
}