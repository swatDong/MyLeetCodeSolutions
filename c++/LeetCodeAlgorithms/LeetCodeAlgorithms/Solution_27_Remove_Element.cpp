#include <iostream>
using namespace std;

class Solution {
public:
	int removeElement(int A[], int n, int elem) {
		int len = 0;
		if (n == 0) return 0;
		for (int i = 0; i < n; i++) {
			if (A[i] != elem) {
				A[len] = A[i];
				len++;
			}
		}
		return len;
	}
};

//int main() {
//	int a[6] = { 3, 2, 3, 8, 4, 6 };
//	Solution s;
//	cout << s.removeElement(a, 6, 3) << endl;
//	return 0;
//}

//Given an array and a value, remove all instances of that value in place and return the new length.
//
//The order of elements can be changed.It doesn't matter what you leave beyond the new length.