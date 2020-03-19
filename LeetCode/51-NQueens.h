#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution_51 {
private:
	vector<vector<string>> res;

public:
	vector<vector<string>> solveNQueens(int n) {
		vector<string> board(n, string(n, '.'));
		backtrack(board, 0);
		return res;
	}
	void backtrack(vector<string> &board, int row) {
		int n = board.size();
		if (row == n) {
			res.push_back(board);
			return;
		}
		for (int col = 0; col < n; ++col) {
			if (isInValid(board, row, col))continue;
			board[row][col] = 'Q';
			backtrack(board, row + 1);
			board[row][col] = '.';
		}
	}
	bool isInValid(const vector<string> &board, int row, int col) {
		int n = board.size();
		for (int i = row - 1; i >= 0; --i) {
			if (board[i][col] == 'Q')return true;
		}
		for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
			if (board[i][j] == 'Q')return true;
		}
		for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j) {
			if (board[i][j] == 'Q')return true;
		}
		return false;
	}
	void output() {
		for (auto &board : res) {
			printBoard(board);
		}
	}
	void printBoard(const vector<string> &board) {
		for (auto &s : board) {
			cout << s << endl;
		}
		cout << endl;
	}
};

void test_51() {
	int n;
	cin >> n;
	Solution_51 s = Solution_51();
	s.solveNQueens(n);
	s.output();
}