#include <iostream>
using namespace std;

class Solution {
public:
	int removeDuplicates(int A[], int n) {
		int len = 0, curIndex = 0;
		if (n == 0) return 0;
		int last = A[curIndex];
		curIndex++;
		while (curIndex < n) {
			if (last != A[curIndex]) {
				A[len] = last;
				len++;
				last = A[curIndex];
			}
			curIndex++;
		}
		A[len] = last;
		return len + 1;
	}
};

//int main() {
//	int a[6] = { 1, 1, 2, 3, 4, 4 };
//	Solution s;
//	cout << s.removeDuplicates(a, 6) << endl;
//	return 0;
//}

//Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
//
//Do not allocate extra space for another array, you must do this in place with constant memory.
//
//For example,
//Given input array A = [1, 1, 2],
//
//Your function should return length = 2, and A is now[1, 2].