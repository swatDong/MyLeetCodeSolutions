#include <cstdio>
#include <utility>
using namespace std;

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

class Solution {
public:
	bool isPalindrome(int x) {
		return x >= 0 && x == reverse(x);
	}
};

//int main() {
//	Solution s;
//	printf("%d\n", s.isPalindrome(-2147447412));
//	return 0;
//}

//Determine whether an integer is a palindrome.Do this without extra space.
//
//click to show spoilers.
//
//Some hints :
//Could negative integers be palindromes ? (ie, -1)
//
//If you are thinking of converting the integer to string, note the restriction of using extra space.
//
//You could also try reversing an integer.However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow.How would you handle such case ?
//
//There is a more generic way of solving this problem.