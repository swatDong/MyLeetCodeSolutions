#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/**
* Definition for singly-linked list.
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct cmp_23{
	bool operator() (ListNode *a, ListNode *b){
		return a->val > b->val;
	}
};

class Solution {
public:
	ListNode *mergeKLists(vector<ListNode *> &lists) {
		priority_queue<ListNode *, vector<ListNode *>, cmp_23> candidates;
		for (ListNode *ln : lists) {
			if (ln != NULL) {
				candidates.push(ln);
			}
		}
		ListNode *ans = NULL, *cur = NULL, *tmp;
		while (!candidates.empty()) {
			tmp = candidates.top();
			candidates.pop();
			if (cur == NULL) {
				ans = cur = tmp;
			}
			else {
				cur->next = tmp;
				cur = tmp;
			}
			if (tmp->next != NULL) {
				candidates.push(tmp->next);
			}
		}
		return ans;
	}
};

//int main() {
//	ListNode* l1 = new ListNode(1);
//	ListNode* l2 = new ListNode(2);
//	ListNode* l3 = new ListNode(3);
//	ListNode* l4 = new ListNode(4);
//	ListNode* l5 = new ListNode(5);
//	ListNode* l6 = new ListNode(6);
//	ListNode* l7 = new ListNode(7);
//	ListNode* l8 = new ListNode(8);
//	ListNode* l9 = new ListNode(9);
//	ListNode* l10 = new ListNode(10);
//	l1->next = l2;
//	l2->next = l3;
//	l4->next = l5;
//	l5->next = l6;
//	l6->next = l7;
//	l8->next = l9;
//	l9->next = l10;
//	vector<ListNode *> lists{ l1, l4, l8 };
//	Solution s;
//	s.mergeKLists(lists);
//	return 0;
//}

//Merge k sorted linked lists and return it as one sorted list.Analyze and describe its complexity.