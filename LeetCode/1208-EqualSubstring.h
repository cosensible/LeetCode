#include "common.h"
using namespace std;

// ǰ׺��
class Solution_1208 {
public:
	int equalSubstring(string s, string t, int maxCost) {
		int m = s.size(), n = t.size();
		if (m != n || maxCost < 0 || m == 0) return 0;
		// �Ӵ� (-1,i] �Ŀ�����Ϊ diff[i]. ÿ���Ӵ� s(i,j] �Ŀ�����Ϊ diff[j]-diff[i]
		vector<int> diff(m + 1, 0);
		for (int i = 0; i < m; ++i) {
			diff[i + 1] = abs(s[i] - t[i]);
			diff[i + 1] += diff[i];
		}
		int maxLen = 0;
		for (int l = 0, r = 1; r <= m;) {
			if (diff[r] - diff[l] <= maxCost) {
				maxLen = max(maxLen, r - l);
				++r;
			}
			else {
				++l;
			}
		}
		return maxLen;
	}
};

// ˫ָ�뷨
class Solution_1208_2P {
public:
	int equalSubstring(string s, string t, int maxCost) {
		int maxLen = 0;
		for (int l = 0, r = 0; r < s.size();) {
			if (abs(s[r] - t[r]) <= maxCost) { // �Ϸ���������Դռ�ã���չ�ұ߽�
				maxCost -= abs(s[r] - t[r]);
				++r;
				maxLen = max(maxLen, r - l); // ��Ϸ�����󳤶�
			}
			else { // �Ƿ����ͷ���Դռ�ã�ѹ����߽�
				maxCost += abs(s[l] - t[l]);
				++l;
			}
		}
		return maxLen;
	}
};

void test_1208() {
	int ans = Solution_1208().equalSubstring("abcd", "acde", 0);
	cout << (ans == 1) << endl;
}