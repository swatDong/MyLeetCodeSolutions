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
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		ListNode *ans = NULL, *cur = NULL;
		while ((l1 != NULL) && (l2 != NULL)) {
			if (l1->val < l2->val) {
				if (cur == NULL) {
					ans = cur = l1;
				}
				else {
					cur->next = l1;
					cur = l1;
				}
				l1 = l1->next;
			}
			else {
				if (cur == NULL) {
					ans = cur = l2;
				}
				else {
					cur->next = l2;
					cur = l2;
				}
				l2 = l2->next;
			}
		}
		if (cur == NULL) {
			ans = (l1 == NULL) ? l2 : l1;
		}
		else {
			cur->next = (l1 == NULL) ? l2 : l1;
		}
		return ans;
	}
};

//int main() {
//	ListNode* l1 = new ListNode(1);
//	ListNode* l2 = new ListNode(2);
//	ListNode* l3 = new ListNode(3);
//	l2->next = l3;
//	Solution s;
//	s.mergeTwoLists(l1, l2);
//	return 0;
//}

//Merge two sorted linked lists and return it as a new list.The new list should be made by splicing together the nodes of the first two lists.