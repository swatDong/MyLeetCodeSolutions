#include <iostream>
#include <string>
#include <vector>
using namespace std;

static string numToLetter[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		int dLen = digits.length();
		if (dLen == 0) {
			return vector<string>();
		}
		int* indexes = new int[dLen];
		int total = 1;
		for (int i = 0; i < dLen; i++) {
			indexes[i] = numToLetter[digits[i] - '2'].length();
			total *= indexes[i];
		}

		vector<string> ans(total);
		char* cs = new char[dLen + 1];
		cs[dLen] = '\0';
		for (int i = 0; i < total; i++) {
			int ii = i;
			for (int j = 0; j < dLen; j++) {
				cs[j] = numToLetter[digits[j] - '2'].at(ii % indexes[j]);
				ii = ii / indexes[j];
			}
			ans[i] = string(cs);
		}
		return ans;
	}
};

//int main() {
//	Solution s;
//	vector<string> ans = s.letterCombinations("23");
//	for (string s : ans) {
//		cout << s.c_str() << endl;
//	}
//	return 0;
//}

//Given a digit string, return all possible letter combinations that the number could represent.
//
//A mapping of digit to letters(just like on the telephone buttons) is given below.
//
//
//
//Input:Digit string "23"
//  Output : ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
//	   Note :
//			Although the above answer is in lexicographical order, your answer could be in any order you want.