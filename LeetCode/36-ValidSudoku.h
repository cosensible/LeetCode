#include <vector>
#include <iostream>

using namespace std;

class Solution_36 {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				if (board[i][j] == '.') continue;
				char num = board[i][j];
				board[i][j] = '.';
				if (!isValid(board, i, j, num)) return false;
				board[i][j] = num;
			}
		}
		return true;
	}

	bool isValid(vector<vector<char>>& board, int pi, int pj, char num) {
		for (int i = 0; i < 9; ++i) {
			if (board[i][pj] == num) return false;
			if (board[pi][i] == num) return false;
			if (board[pi / 3 * 3 + i / 3][pj / 3 * 3 + i % 3] == num) return false;
		}
		return true;
	}
};

void test_36() {
	vector<vector<char>> board = {
	{'8', '3', '.', '.', '7', '.', '.', '.', '.'},
	{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
	{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
	{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
	{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
	{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
	{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
	{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
	{'.', '.', '.', '.', '8', '.', '.', '7', '9'} };
	cout << Solution_36().isValidSudoku(board) << endl;
}