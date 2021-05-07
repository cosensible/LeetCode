#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution_71 {
public:
	// 将字符串以 '/' 分割为文件或目录名称的集合，遇到 '.' 忽略，遇到 '..' 删掉前一个名称
	string simplifyPath(string path) {
		vector<string> names; // 存储每个目录或文件的名称
		int i = 1, j = 0, n = path.size(); // j 为上一个 '/' 的位置，i 为当前 '/' 的位置或字符串结尾
		for (; i < n; ++i) {
			while (i < n && path[i] != '/') ++i;
			if (i - j == 1) { // 连续出现 '/'
				j = i;
				continue;
			}
			string name = path.substr(j + 1, i - j - 1); // 获取两个 '/' 之间的目录或文件名称
			j = i;
			if (name == ".") continue; // '.' 表示当前目录，跳过
			if (name == "..") { // '..' 表示上一层目录，需要删除前一个名称
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
		// 若 ans=="/"，直接返回，否则需要去掉末尾的 '/'
		if (ans.size() > 1) ans.pop_back();
		return ans;
	}
};


void test_71() {
	string path = "/a/./b/../../c/";
	string ans = Solution_71().simplifyPath(path);
	cout << (ans == "/c") << endl;
}