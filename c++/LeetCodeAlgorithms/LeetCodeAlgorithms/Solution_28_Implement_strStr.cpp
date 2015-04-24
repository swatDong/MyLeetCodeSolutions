#include <iostream>
using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {
		int l1 = haystack.length(), l2 = needle.length();
		if (l1 == 0) return (l2 == 0) ? 0 : -1;
		if (l2 == 0) return 0;
		int i = 0, j = 0;
		while (i != l1) {
			if (haystack.at(i) == needle.at(j)) {
				i++;
				j++;
				if (j == l2) return i - j;
			}
			else {
				i = i - j + 1;
				j = 0;
			}
		}
		return -1;
	}

	int strStrKMP(string haystack, string needle) {
		int l1 = haystack.length(), l2 = needle.length();
		if (l1 == 0) return (l2 == 0) ? 0 : -1;
		if (l2 == 0) return 0;

		int *next = new int[l2 + 1];
		next[0] = -1;
		int i = 0, j = -1;
		while (i < l2) {
			if (j == -1 || needle.at(i) == needle.at(j)) {
				next[++i] = ++j;
			}
			else {
				j = next[j];
			}
		}

		i = 0; j = 0;
		while (i < l1 && j < l2) {
			if (j == -1 || haystack.at(i) == needle.at(j)) {
				i++;
				j++;
			}
			else {
				j = next[j];
			}
		}
		if (j == l2) return i - j;
		return -1;
	}
};

//int main() {
//	Solution s;
//	cout << s.strStr("barfoo", "foo") << endl;
//	return 0;
//}

//Implement strStr().
//
//Returns the index of the first occurrence of needle in haystack, or - 1 if needle is not part of haystack.
//
//Update(2014 - 11 - 02) :
//The signature of the function had been updated to return the index instead of the pointer.If you still see your function signature returns a char * or String, please click the reload button  to reset your code definition.