#include <vector>
#include <iostream>

using namespace std;

class Solution_37 {
public:
	void solveSudoku(vector<vector<char>>& board) {
		backtrack(board, 0, 0);
	}

	bool backtrack(vector<vector<char>>& board, int pi, int pj) {
		if (pi == 9)
			return true;
		if (pj == 9)
			return backtrack(board, pi + 1, 0);
		if (board[pi][pj] != '.')
			return backtrack(board, pi, pj + 1);

		for (char c = '1'; c <= '9'; ++c) {
			if (isValid(board, pi, pj, c)) {
				board[pi][pj] = c;
				if (backtrack(board, pi, pj + 1)) return true;
				board[pi][pj] = '.';
			}
		}
		return false;
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

void test_37() {
	vector<vector<char>> board = {
	{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
	{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
	{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
	{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
	{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
	{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
	{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
	{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
	{'.', '.', '.', '.', '8', '.', '.', '7', '9'} };
	Solution_37().solveSudoku(board);
	for (int i = 0; i < board.size(); ++i) {
		for (int j = 0; j < board[0].size(); ++j) {
			cout << board[i][j] << ",";
		}
		cout << endl;
	}
}