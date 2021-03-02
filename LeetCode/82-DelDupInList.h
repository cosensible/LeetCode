#include "common.h"
using namespace std;

class Solution_82 {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == nullptr || head->next == nullptr) return head;
		ListNode *dum = new ListNode(0, head);
		ListNode *pre = dum, *cur = head; // pre 为重复节点之前的节点
		while (cur) {
			// 找到重复当前数字的最后一个节点
			while (cur->next&&cur->val == cur->next->val) {
				cur = cur->next;
			}
			if (cur != pre->next) { // 当前节点重复, 链表指向重复节点之后
				ListNode *p = pre->next;
				pre->next = cur->next;

				// 删除重复节点
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