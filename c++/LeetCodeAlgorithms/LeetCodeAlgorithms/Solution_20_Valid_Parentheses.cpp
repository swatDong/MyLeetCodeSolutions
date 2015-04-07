#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
	bool isValid(string s) {
		int len = s.length();
		if (len % 2 == 1) {
			return false;
		}
		stack<char> seq;
		for (int i = 0; i < len; i++) {
			char c = s[i];
			switch (c) {
			case '(':
				seq.push(c);
				break;
			case ')':
				if (seq.empty() || seq.top() != '(') {
					return false;
				}
				else {
					seq.pop();
				}
				break;
			case '[':
				seq.push(c);
				break;
			case ']':
				if (seq.empty() || seq.top() != '[') {
					return false;
				}
				else {
					seq.pop();
				}
				break;
			case '{':
				seq.push(c);
				break;
			case '}':
				if (seq.empty() || seq.top() != '{') {
					return false;
				}
				else {
					seq.pop();
				}
				break;
			default:
				return false;
			}
		}
		return seq.empty();
	}
};

//int main() {
//	Solution s;
//	cout << s.isValid("()[]{}") << endl;
//	cout << s.isValid("([)]") << endl;
//	return 0;
//}

//Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//
//The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.