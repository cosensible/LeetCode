#include "common.h"
using namespace std;

class Solution_82 {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == nullptr || head->next == nullptr) return head;
		ListNode *dum = new ListNode(0, head);
		ListNode *pre = dum, *cur = head; // pre Ϊ�ظ��ڵ�֮ǰ�Ľڵ�
		while (cur) {
			// �ҵ��ظ���ǰ���ֵ����һ���ڵ�
			while (cur->next&&cur->val == cur->next->val) {
				cur = cur->next;
			}
			if (cur != pre->next) { // ��ǰ�ڵ��ظ�, ����ָ���ظ��ڵ�֮��
				ListNode *p = pre->next;
				pre->next = cur->next;

				// ɾ���ظ��ڵ�
				while (p != pre->next) {
					ListNode *tmp = p;
					p = p->next;
					delete tmp;
				}
			}
			else {
				pre = cur;
			}
			cur = pre->next;
		}
		return dum->next;
	}
};

void test_82() {
	vector<int> vi = { 1,1,1,2,4,4,5 };
	ListNode *lst = arr2list(vi);
	lst = Solution_82().deleteDuplicates(lst);
	printList(lst);
}