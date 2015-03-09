#include <iostream>
using namespace std;

class Solution {
public:
	string convert(string s, int nRows) {
		if (nRows == 1) {
			return string(s.c_str());
		}
		int len = s.length();
		char *ans = new char[len + 1];
		ans[len] = '\0';
		int x, y, oIndex, index = 0;
		x = 0;
		while (true) {
			oIndex = 2 * x * (nRows - 1);
			if (oIndex < len) {
				ans[index++] = s[oIndex];
				x++;
			}
			else {
				break;
			}
		}
		for (y = 1; y < nRows - 1; y++) {
			x = 0;
			while (true) {
				oIndex = 2 * x * (nRows - 1) + y;
				if (oIndex < len) {
					ans[index++] = s[oIndex];
				}
				else {
					break;
				}
				oIndex = 2 * (x + 1) * (nRows - 1) - y;
				if (oIndex < len) {
					ans[index++] = s[oIndex];
					x++;
				}
				else {
					break;
				}
			}
		}
		x = 0;
		while (true) {
			oIndex = (2 * x + 1) * (nRows - 1);
			if (oIndex < len) {
				ans[index++] = s[oIndex];
				x++;
			}
			else {
				break;
			}
		}
		return string(ans);
	}
};

//int main() {
//	Solution s;
//	cout << s.convert("PAYPALISHIRING", 3).c_str() << endl;
//	return 0;
//}

//The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
//
//P   A   H   N
//A P L S I I G
//Y   I   R
//And then read line by line : "PAHNAPLSIIGYIR"
//Write the code that will take a string and make this conversion given a number of rows :
//
//string convert(string text, int nRows);
//convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".