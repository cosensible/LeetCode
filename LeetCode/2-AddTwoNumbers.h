#include "common.h"
using namespace std;

class Solution_2 {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr) return l2;
		if (l2 == nullptr) return l1;

		ListNode *head = l1, *cur = l1;
		int x = 0, y = 0, sum = 0;
		while (l1 || l2) {
			x = l1 ? l1->val : 0;
			y = l2 ? l2->val : 0;
			cur = l1 ? l1 : l2; // 若l1不为空, 保存结果到l1; l1为空, 保存结果到l2

			sum += (x + y);
			cur->val = sum % 10;
			sum /= 10;

			l1 = l1 ? l1->next : nullptr;
			l2 = l2 ? l2->next : nullptr;
			if (l1 == nullptr) cur->next = l2; // 若l1比l2短, 链接l2尾部至l1
		}
		if (sum) cur->next = new ListNode(1); // cur 为保存结果的最后一个节点
		return head;
	}
};

void test_2() {
	vector<int> v1 = { 9,9,9,9,9,9,9 };
	vector<int> v2 = { 9,9,9,9 };
	vector<int> v3 = { 8,9,9,9,0,0,0,1 };
	ListNode *l1 = arr2list(v1), *l2 = arr2list(v2), *ans = arr2list(v3);
	ListNode *res = Solution_2().addTwoNumbers(l1, l2);
	cout << isListSame(res, ans) << endl;
}