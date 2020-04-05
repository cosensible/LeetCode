#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution_49 {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, vector<string>> mp;
		for (int i = 0; i < strs.size(); ++i) {
			string s = strs[i];
			sort(s.begin(), s.end());
			if (mp.find(s) != mp.end()) {
				mp[s].push_back(std::move(strs[i]));
			}
			else {
				mp.emplace(std::move(s), vector<string>(1, std::move(strs[i])));
			}
		}

		vector<vector<string>> res;
		for (auto &entry : mp) {
			res.push_back(std::move(entry.second));
		}
		return res;
	}
};