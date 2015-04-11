#include <iostream>
using namespace std;

/**
* Definition for singly-linked list.
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void swap25(ListNode *p, ListNode *q) {
	ListNode *end = q, *tmp;
	q = q->next;
	while (p != end) {
		tmp = p->next;
		p->next = q;
		q = p;
		p = tmp;
	}
	p->next = q;
}

class Solution {
public:
	ListNode *reverseKGroup(ListNode *head, int k) {
		ListNode *ans, *p, *q, *ahead;
		int count;
		ans = p = q = ahead = head;
		while (p != NULL) {
			count = 1;
			q = p;
			while ((q != NULL) && (count < k)) {
				count++;
				q = q->next;
			}
			if (q == NULL) {
				break;
			}
			swap25(p, q);
			if (ans == p) {
				ans = q;
			}
			else {
				ahead->next = q;
			}
			ahead = p;
			p = p->next;
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
//	l3->next = l4;
//	l4->next = l5;
//	l5->next = l6;
//	l6->next = l7;
//	l7->next = l8;
//	l8->next = l9;
//	l9->next = l10;
//	Solution s;
//	ListNode* p = s.reverseKGroup(l1, 11);
//	while (p != NULL) {
//		cout << p->val << endl;
//		p = p->next;
//	}
//	return 0;
//}

//Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
//
//If the number of nodes is not a multiple of k then left - out nodes in the end should remain as it is.
//
//You may not alter the values in the nodes, only nodes itself may be changed.
//
//Only constant memory is allowed.
//
//For example,
//Given this linked list : 1->2->3->4->5
//
//For k = 2, you should return : 2->1->4->3->5
//
//For k = 3, you should return : 3->2->1->4->5