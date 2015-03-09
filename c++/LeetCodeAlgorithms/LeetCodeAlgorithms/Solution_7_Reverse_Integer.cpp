#include <cstdio>
#include <utility>
using namespace std;

class Solution {
public:
	int reverse(int x) {
		bool negative = (x < 0);
		long long lx = (long long)x;
		if (negative) {
			lx = -lx;
		}
		long long lans = 0;
		while (lx != 0) {
			int p = lx % 10;
			lx = lx / 10;
			lans = lans * 10 + p;
		}
		if (negative) {
			lans = -lans;
		}
		if (lans < INT_MIN || lans >INT_MAX) {
			return 0;
		}
		else {
			return (int)lans;
		}
	}
};

//int main() {
//	Solution s;
//	printf("%d\n", s.reverse(1463847412));
//	return 0;
//}

//Reverse digits of an integer.
//
//Example1: x = 123, return 321
//	  Example2 : x = -123, return -321
//
//				 click to show spoilers.
//
//				 Have you thought about this ?
//				 Here are some good questions to ask before coding.Bonus points for you if you have already thought through this!
//
//				 If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.
//
//				 Did you notice that the reversed integer might overflow ? Assume the input is a 32 - bit integer, then the reverse of 1000000003 overflows.How should you handle such cases ?
//
//				 For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
//
//				 Update(2014 - 11 - 10) :
//				 Test cases had been added to test the overflow behavior.