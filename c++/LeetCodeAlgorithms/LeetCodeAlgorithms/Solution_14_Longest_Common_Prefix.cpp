#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string> &strs) {
		int len = strs.size();
		if (len < 1) return "";
		char* ans = new char[strs[0].length()];
		int index = 0;
		bool flag = true;
		while (flag) {
			if (index >= (int)strs[0].length()) break;
			char c = strs[0][index];
			for (int i = 1; i < len; i++) {
				if (index >= (int)strs[i].length() || c != strs[i][index]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				ans[index] = c;
				index++;
			}
		}
		ans[index] = '\0';
		return string(ans);
	}
};

//int main() {
//	vector<string> strs = { "asdasdwdwa", "asdffgr", "asdfeew" };
//	Solution s;
//	cout << s.longestCommonPrefix(strs).c_str() << endl;
//	return 0;
//}

//Write a function to find the longest common prefix string amongst an array of strings.