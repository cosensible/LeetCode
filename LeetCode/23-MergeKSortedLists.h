#include "common.h"

using namespace std;

class Solution_23_PQ {
	struct Comp {
		bool operator()(ListNode *a, ListNode *b) {
			return a->val > b->val; // 小顶堆
		}
	};
public:
	// 优先队列维护当前最小的链表节点
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		priority_queue<ListNode*, vector<ListNode*>, Comp> pq;
		for (ListNode *pn : lists) {
			if (pn) { pq.push(pn); }
		}
		ListNode *pl = new ListNode(), *cur = pl;
		while (!pq.empty()) {
			cur->next = pq.top();
			pq.pop();
			cur = cur->next;
			if (cur->next) { pq.push(cur->next); }
		}
		return pl->next;
	}
};

class Solution_23_DivideConquer {
	ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
		ListNode *dummy = new ListNode(), *cur = dummy;
		while (l1 && l2) {
			if (l1->val < l2->val) {
				cur->next = l1;
				l1 = l1->next;
			}
			else {
				cur->next = l2;
				l2 = l2->next;
			}
			cur = cur->next;
		}
		cur->next = l1 ? l1 : l2;
		return dummy->next;
	}
public:
	// 每两个链表一起合并, 每轮遍历所有节点一次, logK 轮
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.empty()) { return nullptr; }
		int k = lists.size();
		while (k > 1) {
			int idx = 0;
			for (int i = 0; i < k; i += 2) {
				if (i == k - 1) {
					lists[idx++] = lists[i];
				}
				else {
					lists[idx++] = merge2Lists(lists[i], lists[i + 1]);
				}
			}
			k = idx;
		}
		return lists[0];
	}
};

void test_23() {
	vector<vector<int>> vi = { {1,4,5},{1,3,4},{2,6} };
	vector<ListNode*> vl(3);
	for (int i = 0; i < vi.size(); ++i) {
		vl[i] = arr2list(vi[i]);
	}
	vector<int> resi = { 1,1,2,3,4,4,5,6 };
	ListNode *resl = arr2list(resi);
	cout << isListSame(resl, Solution_23_DivideConquer().mergeKLists(vl)) << endl;
}