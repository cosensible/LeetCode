#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution_399 {
	unordered_map<string, vector<pair<string, double>>> graph;
public:
	vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
		vector<double> res(queries.size(), -1.0);
		for (int i = 0; i < equations.size(); ++i) {
			graph[equations[i][0]].push_back({ equations[i][1],values[i] });
			graph[equations[i][1]].push_back({ equations[i][0],1.0 / values[i] });
		}
		for (int i = 0; i < res.size(); ++i) {
			string &beg = queries[i][0];
			string &end = queries[i][1];
			if (graph.find(beg) != graph.end() && graph.find(end) != graph.end()) {
				double value = 1.0;
				unordered_set<string> path;
				if (getValue(beg, end, path, value)) res[i] = value;
			}
		}
		return res;
	}

private:
	bool getValue(const string &beg, const string &end, unordered_set<string> &path, double &value) {
		if (beg == end) return true;
		path.insert(beg);
		for (const auto &adj : graph.at(beg)) {
			if (path.find(adj.first) != path.end()) continue;
			value *= adj.second;
			if (getValue(adj.first, end, path, value)) return true;
			value /= adj.second;
			path.erase(adj.first);
		}
		return false;
	}
};

void test_399() {
	vector<vector<string>> equations = { {"a", "b"},{"b", "c"} };
	vector<double> values = { 2.0,3.0 };
	vector<vector<string>> queries = { {"a", "c"},{"b", "a"},{"a", "e"},{"a", "a"},{"x", "x"} };
	vector<double> res = Solution_399().calcEquation(equations, values, queries);
	for (double d : res) {
		cout << d << "," << endl;
	}
	cout << endl;
}