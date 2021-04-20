#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution_30 {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> ans;
		if (words.empty()) return ans;
		int wnum = words.size(), wlen = words[0].size();
		int window = wnum * wlen; // �Ӵ�����Ϊ���ڴ�С

		unordered_map<string, int> mp; // ��¼ÿ�����ʵ�����
		for (string &w : words) { mp[w]++; }

		for (int i = 0; i + window <= s.size(); ++i) {
			unordered_map<string, int> cmp; // ��¼��ǰ������ÿ�����ʵ�����
			int j = i;
			for (; j - i < window; j += wlen) {
				string stmp = s.substr(j, wlen);
				if (mp.count(stmp) == 0) break; // ���ʲ����ڣ�һ����ƥ��
				cmp[stmp]++; // ���ӵ�������
				if (cmp[stmp] > mp[stmp]) break; // �����������������һ����ƥ��
			}
			if (j - i == window) ans.push_back(i); // j ���ﴰ��ĩβ��˵�������Ӵ���������
		}
		return ans;
	}

	vector<int> findSubstringFast(string s, vector<string>& words) {
		vector<int> ans;
		if (words.empty()) return ans;
		int wnum = words.size(), wlen = words[0].size();
		int window = wnum * wlen;

		unordered_map<string, int> mp;
		for (string &w : words) { mp[w]++; }
		// ��Ϊ����ÿ���ƶ�һ�����ʵĳ��ȣ����Է�Ϊ wlen �������ÿ����������ֱ��� [0, wlen-1]
		for (int k = 0; k < wlen; ++k) {
			unordered_map<string, int> cmp; // ��ǰ���ڰ����ĸ��ֵ��ʵ�����
			int i = k, j = k; // ����ÿ��������Ƚ����ұ߽� i �� j ������㣬Ȼ��ִ�д��ڵĻ�����ÿ�λ���һ�����ʵĳ���
			// ��߽絽�ַ���ĩβӦ������Ϊ���ڴ�С���ұ߽絽ĩβӦ��������һ�����ʵĳ���
			while (i + window <= s.size() && j + wlen <= s.size()) {
				string stmp = s.substr(j, wlen); // �õ���ǰ����
				if (mp.count(stmp) == 0) { // ���ʲ��ڵ��ʱ��У��޷��γɺϷ���������߽��ƶ��� j+wlen
					j += wlen;
					i = j;
					cmp.clear();
				}
				else { // �����ڵ��ʱ��У���չ�ұ߽磬����������һ
					cmp[stmp]++;
					j += wlen;
					// ������������Ƿ�����С��߽�ֱ���Ϸ������µ�������
					while (cmp[stmp] > mp[stmp]) {
						cmp[s.substr(i, wlen)]--;
						i += wlen;
					}
					// ������ڴ�С�ﵽ window�������ҵ��Ϸ�������¼��������С��߽磬��������
					if (j - i == window) {
						ans.push_back(i);
						cmp[s.substr(i, wlen)]--;
						i += wlen;
					}
				}
			}
		}
		return ans;
	}
};


void test_30() {
	string s = "barfoothefoobarman";
	vector<string> words = { "foo","bar" };
	//auto ans = Solution_30().findSubstring(s, words);
	auto ans = Solution_30().findSubstringFast(s, words);
	for (int i : ans) cout << i << " ";
	cout << endl;
}