#include <cstdio>
#include <iostream>
#include <queue>
#include <set>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int ans = 0, curLen = 0;
		queue<char> subString;
		set<char> chars;
		char c;
		for (int i = 0; i < (int)s.length(); i++) {
			c = s[i];
			if (chars.find(c) != chars.end()) {
				if (ans < curLen) {
					ans = curLen;
				}
				while (true) {
					char f = subString.front();
					chars.erase(f);
					subString.pop();
					curLen--;
					if (f == c) {
						break;
					}
				}
			}
			chars.insert(c);
			subString.push(c);
			curLen++;
		}
		if (ans < curLen) {
			ans = curLen;
		}
		return ans;
	}
};

int main() {
	Solution s;
	cout << s.lengthOfLongestSubstring("abcabcbb") << endl;
	return 0;
}

//Given a string, find the length of the longest substring without repeating characters.For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.