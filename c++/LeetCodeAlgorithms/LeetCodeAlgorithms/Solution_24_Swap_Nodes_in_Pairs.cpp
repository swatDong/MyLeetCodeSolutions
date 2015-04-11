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

void swap24(ListNode *p, ListNode *q) {
	p->next = q->next;
	q->next = p;
}

class Solution {
public:
	ListNode *swapPairs(ListNode *head) {
		ListNode *ans, *p, *q, *ahead;
		ans = p = ahead = head;
		while (p != NULL) {
			q = p->next;
			if (q == NULL) {
				break;
			}
			swap24(p, q);
			if (ans == ahead) {
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
//	s.swapPairs(l1);
//	return 0;
//}

//Given a linked list, swap every two adjacent nodes and return its head.
//
//For example,
//Given 1->2->3->4, you should return the list as 2->1->4->3.
//
//Your algorithm should use only constant space.You may not modify the values in the list, only nodes itself can be changed.