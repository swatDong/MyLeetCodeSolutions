#include <iostream>
using namespace std;

struct RegularNode {
	char e;	// the char, or '.' means any char
	int star;	// -1 means no *, other means has * and how many char(s) matched
	RegularNode *next;
	RegularNode(char c) : e(c), star(-1), next(NULL) {}
};

bool match(RegularNode* cur, const char *s, int index, int sLen) {
	if (cur == NULL && index == sLen) return true;
	if (cur == NULL && index < sLen) return false;
	if (cur != NULL && index == sLen) {
		if (cur->star != -1) {
			return match(cur->next, s, index, sLen);
		}
		else {
			return false;
		}
	}
	char c = s[index];
	if (cur->star == -1) {
		if (cur->e == '.' || cur->e == c) {
			return match(cur->next, s, index + 1, sLen);
		}
		else {
			return false;
		}
	}
	else {
		if (cur->e == '.' || cur->e == c) {
			cur->star++;
			if (match(cur, s, index + 1, sLen)) {
				return true;
			}
			else {
				cur->star--;
				return match(cur->next, s, index, sLen);
			}
		}
		else {
			return match(cur->next, s, index, sLen);
		}
	}
}

class Solution {
public:
	bool isMatch(const char *s, const char *p) {
		RegularNode *head = NULL, *cur = NULL;
		int pLen = strlen(p);
		for (int i = 0; i < pLen; i++) {
			if (p[i] != '*') {
				RegularNode *rn = new RegularNode(p[i]);
				if (head == NULL) {
					head = rn;
					cur = rn;
				}
				else {
					cur->next = rn;
					cur = rn;
				}
			}
			else {
				cur->star = 0;
			}
		}
		return match(head, s, 0, strlen(s));
	}
};

//int main() {
//	Solution s;
//	cout << s.isMatch("ab", ".*c") << endl;
//	return 0;
//}

//Implement regular expression matching with support for '.' and '*'.
//
//'.' Matches any single character.
//'*' Matches zero or more of the preceding element.
//
//The matching should cover the entire input string(not partial).
//
//The function prototype should be :
//bool isMatch(const char *s, const char *p)
//
//Some examples :
//isMatch("aa", "a") ¡ú false
//isMatch("aa", "aa") ¡ú true
//isMatch("aaa", "aa") ¡ú false
//isMatch("aa", "a*") ¡ú true
//isMatch("aa", ".*") ¡ú true
//isMatch("ab", ".*") ¡ú true
//isMatch("aab", "c*a*b") ¡ú true