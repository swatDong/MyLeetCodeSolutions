#include <iostream>
using namespace std;

int romanCharToInt(char c) {
	switch (c) {
	case 'M':
		return 1000;
	case 'D':
		return 500;
	case 'C':
		return 100;
	case 'L':
		return 50;
	case 'X':
		return 10;
	case 'V':
		return 5;
	case 'I':
		return 1;
	default:
		return 0;
	}
}

class Solution {
public:
	int romanToInt(string s) {
		int ans = 0;
		int len = s.length();
		int prev = INT_MAX;
		for (int i = 0; i < len; i++) {
			int cur = romanCharToInt(s[i]);
			if (cur > prev) {
				ans = ans - prev - prev;
			}
			ans += cur;
			prev = cur;
		}
		return ans;
	}
};

//int main() {
//	Solution s;
//	cout << s.romanToInt("MCXIV") << endl;
//	return 0;
//}

//Given a roman numeral, convert it to an integer.
//
//Input is guaranteed to be within the range from 1 to 3999.