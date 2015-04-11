#include <iostream>
#include <vector>
using namespace std;

void nextParenthesis(vector<string>& ans, string cur, int pused, int qused, int n) {
	if (qused == n) {
		ans.push_back(cur);
		return;
	}
	if (pused < n) {
		if (pused > qused) {
			nextParenthesis(ans, cur + "(", pused + 1, qused, n);
			nextParenthesis(ans, cur + ")", pused, qused + 1, n);
		}
		else {
			nextParenthesis(ans, cur + "(", pused + 1, qused, n);
		}
	}
	else {
		nextParenthesis(ans, cur + ")", n, qused + 1, n);
	}
}

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> ans;
		nextParenthesis(ans, "", 0, 0, n);
		return ans;
	}
};

//int main() {
//	Solution s;
//	vector<string> ans = s.generateParenthesis(4);
//	for (string s : ans) {
//		cout << s.c_str() << endl;
//	}
//	return 0;
//}

//Given n pairs of parentheses, write a function to generate all combinations of well - formed parentheses.
//
//For example, given n = 3, a solution set is :
//
//"((()))", "(()())", "(())()", "()(())", "()()()"