#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;


class Solution_149 {
	using ll = long long;
	const ll epsilon = 100000LL;
public:
	// Ҫ������ж��ٸ�����ͬһ��ֱ���ϣ����Դ�ÿ����������󾭹��õ��ֱ�������������ٸ�������
	// �����õ��ֱ�߿���б��ֵΨһ��ʶ������õ�������㹹�ɵ�б�ʴ�С��ĳб��ֵ���ִ�����࣬�����ֱ�߾������ĵ�
	// ��Ҫ������������õ��غ� �� ֱ���� y ��ƽ�е����
	int maxPoints(vector<vector<int>>& points) {
		if (points.size() < 3) return points.size();
		int maxCnt = 0;
		for (int i = 0; i < points.size(); ++i) { // �Ӹ��������Ѱ��ֱ��
			int imaxCnt = 0, vCnt = 0, dup = 1;   // ��������б�ʵ��������� y ��ƽ�е�б�ʵ��������õ���ظ�����
			unordered_map<ll, int> cnt;
			int x1 = points[i][0], y1 = points[i][1];
			for (int j = i + 1; j < points.size(); ++j) { // n ����֮���� n(n-1)/2 ����
				int x2 = points[j][0], y2 = points[j][1];
				if (x1 == x2 && y1 == y2) { dup++; } // �����ظ��㣬�����õ��ֱ�����ٰ��� dup ����
				else if (x1 == x2) { // ���ɵ�ֱ���� y ��ƽ�У�б��Ϊ����󣬵�������
					vCnt++;
					imaxCnt = max(vCnt, imaxCnt);
				}
				else {
					double k = 1.0*(y1 - y2) / (x1 - x2);
					ll key = static_cast<ll>(k*epsilon);
					cnt[key]++;
					imaxCnt = max(cnt[key], imaxCnt);
				}
			}
			imaxCnt += dup; // ֱ�߾�����������������ϸõ㱻�ظ��Ĵ���
			maxCnt = max(imaxCnt, maxCnt);
		}
		return maxCnt;
	}
};


void test_149() {
	vector<vector<int>> points = { {1,1 }, { 3,2 }, { 5,3 }, { 4,1 }, { 2,3 }, { 1,4 } };
	cout << (Solution_149().maxPoints(points) == 4) << endl;
}