#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution_79 {
	vector<vector<int>> dirs = { {-1,0},{0,-1},{1,0},{0,1} };
public:
	bool exist(vector<vector<char>>& board, string word) {
		string rword(word.rbegin(), word.rend() - 1);
		for (int i = 0; i < board.size(); ++i) {
			for (int j = 0; j < board[0].size(); ++j) {
				if (board[i][j] == word[0]) {
					board[i][j] = '.';
					if (search(board, rword, i, j)) return true;
					board[i][j] = word[0];
				}
			}
		}
		return false;
	}

private:
	bool search(vector<vector<char>> &board, string &word, int i, int j) {
		if (word.size() == 0) return true;
		char c = word.back();
		for (auto &d : dirs) {
			if (isValid(board, c, i + d[0], j + d[1])) {
				board[i + d[0]][j + d[1]] = '.';
				word.pop_back();
				if (search(board, word, i + d[0], j + d[1])) return true;
				word.push_back(c);
				board[i + d[0]][j + d[1]] = c;
			}
		}
		return false;
	}

	bool isValid(vector<vector<char>> &board, char c, int i, int j) {
		if (i >= 0 && i < board.size() && j >= 0 && j < board[0].size())
			return board[i][j] == c;
		return false;
	}
};

void test_79() {
	vector<vector<char>> board = { {'A', 'B', 'C', 'E'},{'S', 'F', 'C', 'S'},{'A', 'D', 'E', 'E'} };
	string word1 = "ABCCED", word2 = "ABCB";
	Solution_79 s = Solution_79();
	cout << (s.exist(board, word1) && !s.exist(board, word2)) << endl;
}