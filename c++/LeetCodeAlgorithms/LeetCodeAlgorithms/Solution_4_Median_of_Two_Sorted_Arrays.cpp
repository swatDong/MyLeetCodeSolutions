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
	WrapArray aa(A, m);
	WrapArray bb(B, n);
	int begin = 0;
	int end = m - 1;
	int a, b;
	while (true) {
		if ((begin + end) < 0) {	//if -1,0 or 0,-1
			a = -1;
		}
		else {
			a = (begin + end) / 2;
		}
		b = (m + n + 1) / 2 - a - 2;
		if ((aa.get(a) <= bb.get(b + 1)) && (aa.get(a + 1) >= bb.get(b))) {
			break;
		}
		else if (aa.get(a) > bb.get(b + 1)){
			if (end != a) {
				end = a;
			}
			else {
				end = a - 1;
			}
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
	if (aa.get(a) < bb.get(b)) {
		return bb.get(b);
	}
	else {
		return aa.get(a);
	}
}

double isOuShu(int A[], int m, int B[], int n) {
	WrapArray aa(A, m);
	WrapArray bb(B, n);
	int begin = 0;
	int end = m - 1;
	int a, b;
	while (true) {
		if ((begin + end) < 0) {
			a = -1;
		}
		else {
			a = (begin + end) / 2;
		}
		b = (m + n) / 2 - a - 2;
		if ((aa.get(a) <= bb.get(b + 1)) && (aa.get(a + 1) >= bb.get(b))) {
			break;
		}
		else if (aa.get(a) > bb.get(b + 1)){
			if (end != a) {
				end = a;
			}
			else {
				end = a - 1;
			}
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
	double answer = 0;
	if (aa.get(a) < bb.get(b)) {
		answer += bb.get(b);
	}
	else {
		answer += aa.get(a);
	}
	if (aa.get(a + 1) < bb.get(b + 1)) {
		answer += aa.get(a + 1);
	}
	else {
		answer += bb.get(b + 1);
	}
	return answer / 2;
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

//int main() {
//	int a[] = { 3 };
//	int b[] = { 2 };
//	Solution s;
//	printf("%lf\n", s.findMedianSortedArrays(a, 1, b, 1));
//	return 0;
//}

//There are two sorted arrays A and B of size m and n respectively.Find the median of the two sorted arrays.The overall run time complexity should be O(log(m + n)).