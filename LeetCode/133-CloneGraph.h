#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;


class Solution_133 {
public:
	class Node {
	public:
		int val;
		vector<Node*> neighbors;
		Node() {
			val = 0;
			neighbors = vector<Node*>();
		}
		Node(int _val) {
			val = _val;
			neighbors = vector<Node*>();
		}
		Node(int _val, vector<Node*> _neighbors) {
			val = _val;
			neighbors = _neighbors;
		}
	};

	Node* cloneGraph(Node* node) {
		if (node == nullptr) return nullptr;
		unordered_map<Node*, Node*> mp;
		mp[node] = new Node(node->val);
		queue<Node*> q;
		q.push(node);
		while (!q.empty()) {
			Node *n = q.front();
			q.pop();
			for (Node *neigh : n->neighbors) {
				if (mp.find(neigh) == mp.end()) {
					q.push(neigh);
					mp[neigh] = new Node(neigh->val);
				}
				mp[n]->neighbors.push_back(mp[neigh]);
			}
		}
		return mp[node];
	}
};