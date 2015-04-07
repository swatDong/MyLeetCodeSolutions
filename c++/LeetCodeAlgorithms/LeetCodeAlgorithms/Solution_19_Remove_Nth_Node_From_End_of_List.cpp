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

class Solution {
public:
	ListNode *removeNthFromEnd(ListNode *head, int n) {
		int counter = 0;
		ListNode *n1 = NULL, *n2, *cur;
		n2 = head;
		cur = head;
		while (cur != NULL) {
			if (counter == n) {
				n1 = n2;
				n2 = cur;
				counter = 0;
			}
			cur = cur->next;
			counter++;
		}
		if (n1 == NULL) {
			//TODO: delete head
			head = head->next;
		}
		else {
			while (counter > 1) {
				n1 = n1->next;
				counter--;
			}
			//TODO: delete n1->next
			n1->next = n1->next->next;
		}
		return head;
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
//	s.removeNthFromEnd(l1, 7);
//	return 0;
//}

//Given a linked list, remove the nth node from the end of list and return its head.
//
//For example,
//
//Given linked list : 1->2->3->4->5, and n = 2.
//
//After removing the second node from the end, the linked list becomes 1->2->3->5.
//Note :
//	 Given n will always be valid.
//	 Try to do this in one pass.