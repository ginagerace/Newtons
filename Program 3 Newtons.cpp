
/* ------------------------------------------------
   ggerac3mschro9Prog3.cpp
 
   Program #3: Newton game to get 5 in a row.
               Players alternate placing a piece or
               rotating a column.
   Class: CS 141
   Author: Gina Gerace & Mahal Schroeder
   Lab: Tues 11am
   System:  C++ Windows Dev-C++

   Grading Rubric:

   50 Execution points
         2 Displays header info and instructions on screen when run
         5 Move number and character-to-move update correctly
         3 Handles upper and lower-case user input, spaces between inputs, and 'X' to exit
         5 Does error checking of user input for valid input and space in column
        10 Handles 'R' to rotate a column
        10 Correctly places pieces on board
        15 Detects a win of 5 in a row, and gives the corresponding ending message
   45 Programming Style (Given only if program runs substantially correctly)
         5 Program naming convention is followed
        10 Meaningful identifier names
        10 Comments: Has header and this rubric.  Has comments on each block of code
        10 Appropriate data and control structures 
        10 Code Layout: Appropriate indentation and blank lines
   ------------------------------------------------
*/

#include <iostream>
using namespace std;

// Function to print the board
void PrintBoard(char board[8][5]) {
	cout << endl << " 1   2   3   4   5" << endl
		 << "--- --- --- --- ---" << endl;
	
	int r, c;
	
	for(r=0; r<8; r++) {
		for(c=0; c<5; c++) {
			cout << " " << board[r][c] << "  ";
		}
		cout << endl;
	}
	cout << "--- --- --- --- ---" << endl
		 << " 1   2   3   4   5" << endl;
}

// Funtion to place a piece in column
void PlacePiece(char col, char piece, char board[8][5]) {
	if(board[7][col]=='.')
	{board[7][col] = piece;}
	else if(board[6][col]=='.')
	{board[6][col] = piece;}
	else if(board[5][col]=='.')
	{board[5][col] = piece;}
	else if(board[4][col]=='.')
	{board[4][col] = piece;}	
	else if(board[3][col]=='.')
	{board[3][col] = piece;}
	else if(board[2][col]=='.')
	{board[2][col] = piece;}
	else if(board[1][col]=='.')
	{board[1][col] = piece;}
	else if(board[0][col]=='.')
	{board[0][col] = piece;}
}

// Function to rotate a column
void Rotate(char input, char board[8][5]) {
	int col = input - '0' - 1;		// change from a char to an int
	int count = 0;
	int i;

	for(i=0; i<8; i++) {
		if(board[i][col]!='.')	
		{count++;}
	}
	char temp[count];
	for(i=0; i<=count; i++) {
		temp[i] = board[7-i][col];
	}
	for(i=0; i<count; i++) {
		board[7-i][col] = temp[count-i-1];
	}
}

// Function to check if any row has 5 of the same pieces
bool rowCheck(char x, char board[8][5]) {
	int count = 0;
	for (int i = 0; i < 8; i ++) {
		for (int j = 0; j < 5; j ++) {
			 if (board[i][j] == x)
			{count ++;}
			if (count == 5)
			{return true;}
		}
		count = 0;
	}
	return false;
}

// Function to check if any column has 5 pieces in a row
bool colCheck(char x, char board[8][5]) {
	int count = 0;
	for (int i = 0; i < 5; i ++) { 
		for (int j = 0; j < 8; j ++) { 
			if (board[j][i] == x) {
				count ++;
				if (count == 5)
				{return true;}
			}
		}	
		count = 0;
	}
	return false;
}

// Function to check if there are 5 of the same piece in a diagonal from upper-left to lower-right
bool upDiagCheck(char x, char board[8][5]) {
	int count = 0;
	for (int i = 7; i >3; i--) {
		for (int j = 0; j < 5; j ++) {
			if (board[i-j][j] == x) {
				count ++;
				if (count == 5)
				{return true;}
			}
		}
		count = 0;
	}
	return false;
}

// Function to check if there are 5 of the same piece in a diagonal from lower-left to upper-right
bool lowDiagCheck(char x, char board[8][5]) {
	int count = 0;
	for (int i = 3; i <8; i ++) {
		for (int j = 0; j < 5; j ++) {
			if (board[i+j][j] == x) {
				count ++;
				if (count == 5)
				{return true;}
			}
		}
		count = 0;
	}
	return false;
}

// Function to check for a win
bool Victory(char x, char board[8][5]) {
	int counter = 0;
	if (rowCheck(x, board) == true)
	{ counter ++;}
	if (colCheck(x, board) == true)
	{ counter ++;}
	if (upDiagCheck(x, board) == true)
	{ counter ++;}
	if (lowDiagCheck(x, board) == true)
	{ counter ++;}
	
	if (counter == 1)
	{return true;}
	else
	{ return false;}
}

int main()
{
	// Display identifying information
        cout <<  "Authors: Gina Gerace & Mahal Schroeder" << endl << "Lab: Tues. 11am" << endl
             << "Program: #3, Newton Game" << endl
             << endl;
        
        // Display the instuctions
        cout << "Welcome to the game of Newton, where you try to be the first" << endl << endl 
			<< "to get 5 in a row either vertically, horizontally or diagonally." << endl
        	<< "Two players alternate making moves. On each turn you may enter" << endl
        	<< "the column number where your piece will be placed, where that" << endl
        	<< "piece is inserted from the top and slides down as far as it can" << endl
        	<< "go in that column. You may also enter 'r' to rotate a piece out" << endl
        	<< "of the bottom of a column to be dropped back in at the top of" << endl
        	<< "that column.  Enter 'x' to exit." << endl << endl;
	
	// Create variables 
	char userInput1;
	char userInput2;
	bool stillPlaying = true;
	int turnCount = 1;
	bool currentTurn = true; 	//true means X's turn, false means O's turn
	char board[8][5] = {
						{'.','.','.','.','.'},
						{'.','.','.','.','.'},
						{'.','.','.','.','.'},
						{'.','.','.','.','.'},
						{'.','.','.','.','.'},
						{'.','.','.','.','.'},
						{'.','.','.','.','.'},
						{'.','.','.','.','.'}
						};
	
	// Get user input and perform correct action	
	while (stillPlaying == true) 
	{
		// X's turn
		if(currentTurn == true) {
		
			PrintBoard(board);
			cout << turnCount << ". Enter column number to place X or 'r' to rotate: ";
			cin >> userInput1;
			userInput1 = toupper (userInput1);
			
			if (userInput1 == 'R') {
				cin >> userInput2;
				Rotate(userInput2, board);
				if (Victory('X', board) == true) {
						PrintBoard(board);
						cout << "*** Congratulations X, you just won! ***" << endl;
						exit(0);	
					}
			}
			
			else if (userInput1 == 'X')
				{exit(0);}
			
			else if ((userInput1 == '1') || (userInput1 == '2') || (userInput1 == '3') || (userInput1 == '4') || (userInput1 == '5')) {
				userInput1 = userInput1 - '0' - 1;	// change from a char to an int
			
				// check to see if column is full
				if(board[0][userInput1] != '.')	{
					cout << "*** Sorry, that column is already full.  Please choose another." << endl;
					continue;
				}	
				else {
					PlacePiece(userInput1, 'X', board);
					if (Victory('X', board) == true) {
						PrintBoard(board);
						cout << "*** Congratulations X, you just won! ***" << endl;
						exit(0);	
					}
				}
			}
		
			else {
				cout << "*** Invalid input.  Please retry..." << endl;
				continue;
			}
			turnCount++;
			currentTurn = false;
		}
	
		
		// O's turn
		else if(currentTurn == false) {
			
			PrintBoard(board);
			cout << turnCount << ". Enter column number to place O or 'r' to rotate: ";
			cin >> userInput1;
			userInput1 = toupper (userInput1);
			
			if (userInput1 == 'R') {
				cin >> userInput2;
				Rotate(userInput2, board);
				if (Victory('O', board) == true) {
					PrintBoard(board);
					cout << "*** Congratulations O, you just won! ***" << endl;
					exit(0);
				}
			}
			
			else if (userInput1 == 'X')
				{exit(0);}
			
			else if ((userInput1 == '1') || (userInput1 == '2') || (userInput1 == '3') || (userInput1 == '4') || (userInput1 == '5')) {
				userInput1 = userInput1 - '0' - 1;	// change from a char to an int
				
				// check to see if column is full
				if(board[0][userInput1] != '.')	{
					cout << "*** Sorry, that column is already full.  Please choose another." << endl;
					continue;
				}	
				else 
				{
					PlacePiece(userInput1, 'O', board);
					if (Victory('O', board) == true) {
						PrintBoard(board);
						cout << "*** Congratulations O, you just won! ***" << endl;
						exit(0);
					}
				}
			}	
			
			else {
				cout << "*** Invalid input.  Please retry..." << endl;
				continue;
			}
		
			turnCount++;
			currentTurn = true;
		}
	}
	
	return 0;
}
