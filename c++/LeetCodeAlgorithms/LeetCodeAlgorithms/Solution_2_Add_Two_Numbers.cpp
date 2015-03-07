#include <cstdio>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		ListNode* zero = new ListNode(0);
		zero->next = zero;
		ListNode *ans = NULL, *pre = NULL;
		int carry = 0;
		bool r1 = true, r2 = true;
		while (r1 || r2) {
			ListNode *cur = new ListNode(0);
			int t = l1->val + l2->val + carry;
			carry = t / 10;
			cur->val = t % 10;
			if (ans == NULL) {
				ans = cur;
				pre = cur;
			}
			else {
				pre->next = cur;
				pre = cur;
			}
			l1 = l1->next;
			l2 = l2->next;
			if (l1 == NULL) {
				r1 = false;
				l1 = zero;
			}
			if (l2 == NULL) {
				r2 = false;
				l2 = zero;
			}
		}
		if (carry != 0) {
			ListNode *cur = new ListNode(carry);
			pre->next = cur;
		}
		return ans;
	}
};

//int main() {
//	ListNode* l1 = new ListNode(0);
//	Solution s;
//	s.addTwoNumbers(l1, l1);
//	return 0;
//}

//You are given two linked lists representing two non - negative numbers.The digits are stored in reverse order and each of their nodes contain a single digit.Add the two numbers and return it as a linked list.
//
//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//   Output : 7 -> 0 -> 8