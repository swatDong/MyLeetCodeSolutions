#include <iostream>
using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		int len = s.length();
		int longest = 0, start = 0;
		for (int i = 0; i < len; i++) {
			int l, j;

			l = 1;
			for (j = 1; (i - j >= 0) && (i + j < len); j++) {
				if (s[i - j] == s[i + j]) {
					l += 2;
				}
				else {
					break;
				}
			}
			if (l > longest) {
				longest = l;
				start = i - j + 1;
			}

			l = 0;
			for (j = 1; (i - j >= 0) && (i + j - 1 < len); j++) {
				if (s[i - j] == s[i + j - 1]) {
					l += 2;
				}
				else {
					break;
				}
			}
			if (l > longest) {
				longest = l;
				start = i - j + 1;
			}
		}
		return s.substr(start, longest);
	}
};

//int main() {
//	Solution s;
//	cout << s.longestPalindrome("asdfdaas").c_str() << endl;
//	return 0;
//}

//Given a string S, find the longest palindromic substring in S.You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.