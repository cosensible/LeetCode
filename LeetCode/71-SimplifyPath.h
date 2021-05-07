#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution_71 {
public:
	// ���ַ����� '/' �ָ�Ϊ�ļ���Ŀ¼���Ƶļ��ϣ����� '.' ���ԣ����� '..' ɾ��ǰһ������
	string simplifyPath(string path) {
		vector<string> names; // �洢ÿ��Ŀ¼���ļ�������
		int i = 1, j = 0, n = path.size(); // j Ϊ��һ�� '/' ��λ�ã�i Ϊ��ǰ '/' ��λ�û��ַ�����β
		for (; i < n; ++i) {
			while (i < n && path[i] != '/') ++i;
			if (i - j == 1) { // �������� '/'
				j = i;
				continue;
			}
			string name = path.substr(j + 1, i - j - 1); // ��ȡ���� '/' ֮���Ŀ¼���ļ�����
			j = i;
			if (name == ".") continue; // '.' ��ʾ��ǰĿ¼������
			if (name == "..") { // '..' ��ʾ��һ��Ŀ¼����Ҫɾ��ǰһ������
				if (!names.empty()) names.pop_back();
			}
			else {
				names.push_back(name);
			}
		}
		string ans = "/";
		for (string &s : names) {
			ans += s;
			ans.push_back('/');
		}
		// �� ans=="/"��ֱ�ӷ��أ�������Ҫȥ��ĩβ�� '/'
		if (ans.size() > 1) ans.pop_back();
		return ans;
	}
};


void test_71() {
	string path = "/a/./b/../../c/";
	string ans = Solution_71().simplifyPath(path);
	cout << (ans == "/c") << endl;
}