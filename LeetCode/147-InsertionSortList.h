#include "common.h"
using namespace std;

class Solution_147 {
public:
	ListNode* insertionSortList(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode *dum = new ListNode(0, head);  // ������ head ֮ǰ����ڵ�
		ListNode *cur = head->next, *tail = head; // cur ������ڵ㣬tail �����򲿷ֵ����һ���ڵ�
		while (cur) {
			if (cur->val >= tail->val) { // �Ѿ�������ģ��������
				tail = cur;
			}
			else { // ��ǰ�����Ҳ���λ��
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