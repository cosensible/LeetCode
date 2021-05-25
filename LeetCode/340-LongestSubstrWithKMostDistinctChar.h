#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution_340 {
public:
	// �������ڣ���ϣ��ͳ�ƴ����е��ַ����༰������
	int lengthOfLongestSubstringKDistinct(string s, int k) {
		int ans = 0;
		unordered_map<char, int> cnt;
		for (int l = 0, r = 0; r < s.size(); ++r) {
			cnt[s[r]]++;
			// �ַ����೬�����ƣ��ƶ���߽�ֱ���ַ��������Ҫ��
			// Ҳ���ù�ϣ���¼������ÿ���ַ������ֵ�λ�ã�Ȼ����߽�ֱ���Ƶ�λ����С���ַ�����
			// ��Ҫ��ֵȡ��ϣ����СԪ�أ�ͬ����Ҫ������ϣ��
			while (cnt.size() > k) {
				if (--cnt[s[l]] == 0) cnt.erase(s[l]);
				++l;
			}
			ans = max(ans, r - l + 1);
		}
		return ans;
	}
};


void test_340() {
	string s = "eceba";
	cout << (Solution_340().lengthOfLongestSubstringKDistinct(s, 3) == 4) << endl;
}