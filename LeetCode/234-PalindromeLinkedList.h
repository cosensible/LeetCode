#include "List.h"
#include <vector>
#include <iostream>

using namespace std;

class Solution_234 {
public:
	bool isPalindrome(ListNode* head) {
		ListNode *fast = head, *mid = head;
		while (fast) {
			fast = fast->next;
			if (fast) {
				fast = fast->next;
				mid = mid->next;
			}
		}

		ListNode *pre = nullptr;
		while (mid) {
			ListNode *tmp = mid->next;
			mid->next = pre;
			pre = mid;
			mid = tmp;
		}

		ListNode *front = head, *back = pre;
		while (front && back) {
			if (front->val != back->val) return false;
			front = front->next;
			back = back->next;
		}
		return true;
	}
};


void test_234() {
	vector<int> nv = { 1,2,1 };
	ListNode *list = arr2list(nv);
	cout << Solution_234().isPalindrome(list) << endl;
}
