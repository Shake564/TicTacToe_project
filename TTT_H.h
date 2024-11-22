#ifndef TTT_H
#define TTT_H

class TicTacToe {
private:
	char** Board;
	int getBoardIndex(char c) {
		for (int i = 0; i < 3; i++) {
			for (int ii = 0; ii < 3; ii++) {
				if (Board[i][ii] == c) {
					return i*ii;
				}
			}
		}
		return -1;
	}
	char getBoardat(int row, int col) {
		return Board[row][col];
	}
public:
	TicTacToe();
	~TicTacToe();
	void printBoard();
	int takeTurns();
	char won();
	void InsertBoard(char, int, int);
	int recursive(char,int,int);
};

#endif
