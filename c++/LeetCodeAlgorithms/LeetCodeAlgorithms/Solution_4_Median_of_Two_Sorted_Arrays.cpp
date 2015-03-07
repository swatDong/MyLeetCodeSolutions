#include <cstdio>
#include <utility>
using namespace std;

class WrapArray {
public:
	int* e;
	int len;
	WrapArray(int e[], int len) {
		this->e = e;
		this->len = len;
	}
	int get(int index) {
		if (index == -1) {
			return INT_MIN;
		}
		else if (index == len) {
			return INT_MAX;
		}
		else {
			return e[index];
		}
	}
};

double isJiShu(int A[], int m, int B[], int n) {

}

double isOuShu(int A[], int m, int B[], int n) {
	WrapArray aa(A, m);
	WrapArray bb(B, n);
	int begin = 0;
	int end = m - 1;
	int a, b;
	while (true) {
		a = (begin + end) / 2;
		b = (m + n) / 2 - a - 2;
		if ((aa.get(a) <= bb.get(b + 1)) && (aa.get(a + 1) >= bb.get(b))) {
			break;
		}
		else if (aa.get(a) > bb.get(b + 1)){
			end = a;
		}
		else {
			if (begin != a) {
				begin = a;
			}
			else {
				begin = a + 1;
			}
		}
	}
	// calculate median
}

class Solution {
public:
	double findMedianSortedArrays(int A[], int m, int B[], int n) {
		if (m > n) {
			return findMedianSortedArrays(B, n, A, m);
		}
		if ((m + n) % 2 == 0) {
			return isOuShu(A, m, B, n);
		}
		else {
			return isJiShu(A, m, B, n);
		}
	}
};

int main() {
	int a[] = { 1, 3, 5, 7, 9 };
	int b[] = { 1, 3, 3, 3, 5 };
	Solution s;
	printf("%lf\n", s.findMedianSortedArrays(a, 5, b, 5));
	return 0;
}

//There are two sorted arrays A and B of size m and n respectively.Find the median of the two sorted arrays.The overall run time complexity should be O(log(m + n)).