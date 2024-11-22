#include "TTT_H.h"
#include <iostream>
#include <conio.h>
#include <string>

using namespace std;


TicTacToe::TicTacToe() {
	Board = new char*[3];
	for (int i = 0; i < 3; i++) {
		Board[i] = new char[3];
	}
	for (int i = 0; i < 3; i++) {
		for (int ii = 0; ii < 3; ii++) {
			Board[i][ii] = 'N';
		}
	}
}
TicTacToe::~TicTacToe() {
	for (int i = 0; i < 3; i++) {
		delete Board[i];
	}
	delete Board;
}
char TicTacToe::won() {
	int xCounter = 0, yCounter = 0;
	//checking Horizontal
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (Board[i][j] == 'X') {
				xCounter++;
			}
			else if (Board[i][j] == 'O') {
				yCounter++;
			}
			if (xCounter == 3)
				return 'x';
			else if (yCounter == 3)
				return 'O';
		}
		xCounter = 0;
		yCounter = 0;
	}
	//checking Vertical
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (Board[j][i] == 'X') {
				xCounter++;
			}
			else if (Board[j][i] == 'O') {
				yCounter++;
			}
			if (xCounter == 3)
				return 'x';
			else if (yCounter == 3)
				return 'O';
		}
		xCounter = 0;
		yCounter = 0;
	}
	//checking diagonals
	/*
	    X	L	L
		L	X	L
		L	L	X
	*/
	for (int i = 0; i < 3; i++) {
		if (Board[i][i] == 'X')
			xCounter++;
		if (Board[i][i] == 'O')
			yCounter++;
	}
	if (xCounter == 3)
		return 'x';
	else if (yCounter == 3)
		return 'O';
	xCounter = 0;
	yCounter = 0;
	/*
		L	L	X
		L	X	L
		X	L	L
	*/
	int j = 2;
	for (int i = 0; i < 3; i++) {
		if (Board[i][j] == 'X')
			xCounter++;
		if (Board[i][j] == 'O')
			yCounter++;
		j--;
	}
	if (xCounter == 3)
		return 'x';
	else if (yCounter == 3)
		return 'O';
	return 'n';
}
void TicTacToe::printBoard() {

	system("cls");
	cout << "Printing Board:" << endl<<endl;
	for (int i = 0; i < 3; i++) {
		for (int ii = 0; ii < 3; ii++) {
			cout << Board[i][ii] << "	";
		}
		cout << endl;
	}
	cout << endl;
}
int TicTacToe::takeTurns() {
	int turns = 0;
	bool x = true;
	char xory;
	cout << "Who is making the first move (X or O)?" << endl;
	cin >> xory;
	xory = tolower(xory);
	cout << endl;
	if (xory == 'x') {
		x = true;
	}
	else if (xory == 'o') {
		x = false;
	}
	else {
		cout << "That player doesn't exist" << endl;
		return 0;
	}
	while (true) {
		if (x == true) {
			x = false;
			xory = 'X';
		}
		else {
			x = true;
			xory = 'O';
		}
		turns++;
		cout << "Make your move row then column player "<<xory<<" (Must be between 1 and 3)" << endl;
		int row,col;
		cin >> row >> col;
		cout << endl;
		//user proofing
		recursive(xory,row,col);
		//printing
		printBoard();
		if (won() == 'x') {
			cout << "Player X wins!" << endl;
			break;
		}
		else if (won() == 'o') {
			cout << "Player Y wins!" << endl;
			break;
		}
		else if (turns == 9) {
			cout << "Tie" << endl;
			break;
		}
	}
	return 0;
}
void TicTacToe::InsertBoard(char c,int row, int col) {
	Board[row-1][col-1] = c;
}
//user proofing
int TicTacToe::recursive(char c,int row, int col) {
	if (Board[row - 1][col - 1] == 'N' && (row <= 3 && row > 0 && col <= 3 && col > 0)) {
		//inserting into the board
		InsertBoard(toupper(c), row, col);
		return 0;
	}
	cout<< "Choose a different coordinate" << endl;
	cin >> row >> col;
	recursive(c,row, col);
}