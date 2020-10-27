#include "List.h"
#include <vector>

using namespace std;

class Solution_237 {
public:
	void deleteNode(ListNode* node) {
		// while(node->next&&node->next->next){
		//     node->val=node->next->val;
		//     node=node->next;
		// }
		// node->val=node->next->val;
		// delete node->next;
		// node->next=nullptr;

		ListNode* tmp = node->next;
		node->val = tmp->val;
		node->next = tmp->next;
		delete tmp;
	}
};

void test_237() {
	vector<int> vi = { 4,5,1,9 };
	ListNode *l = arr2list(vi), *li = l;
	while (li && li->val != 4)
		li = li->next;
	Solution_237().deleteNode(li);
	printList(l);
}