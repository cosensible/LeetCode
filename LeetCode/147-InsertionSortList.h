#include "common.h"
using namespace std;

class Solution_147 {
public:
	ListNode* insertionSortList(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode *dum = new ListNode(0, head);  // 便于在 head 之前插入节点
		ListNode *cur = head->next, *tail = head; // cur 待插入节点，tail 已排序部分的最后一个节点
		while (cur) {
			if (cur->val >= tail->val) { // 已经是有序的，无需插入
				tail = cur;
			}
			else { // 从前往后找插入位置
				ListNode *pre = dum;
				while (pre->next->val <= cur->val) pre = pre->next;
				tail->next = cur->next;
				cur->next = pre->next;
				pre->next = cur;
			}
			cur = tail->next;
		}
		return dum->next;
	}
};

void test_147() {
	vector<int> vals = { -1,5,3,4,0 };
	ListNode *list = arr2list(vals);
	ListNode *slist = Solution_147().insertionSortList(list);
	printList(slist); // -1 0 3 4 5
}