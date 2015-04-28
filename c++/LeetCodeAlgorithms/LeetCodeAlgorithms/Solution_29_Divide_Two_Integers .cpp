#include <iostream>
using namespace std;

class Solution {
public:
	int divide(int dividend, int divisor) {
		long long ans = 0;
		int flag = 1;
		if (dividend == 0) return (int)ans;
		long long dd = dividend;
		long long ds = divisor;
		if (dd < 0) {
			dd = -dd;
			flag = -flag;
		}
		if (ds < 0) {
			ds = -ds;
			flag = -flag;
		}

		for (int i = 31; i >= 0; i--) {
			long long t = ds << i;
			if (dd >= t) {
				dd = dd - t;
				ans = ans + ((long long)1 << i);
			}
		}

		if (flag == -1) ans = -ans;
		if (ans > INT_MAX || ans < INT_MIN) {
			return INT_MAX;
		}
		return (int)ans;
	}
};

//int main() {
//	Solution s;
//	cout << s.divide(-2147483648, -1) << endl;
//	cout << s.divide(-9, -4) << endl;
//	cout << s.divide(9, 2) << endl;
//	cout << s.divide(-9, 3) << endl;
//	cout << s.divide(-9, 4) << endl;
//	cout << s.divide(-9, 2) << endl;
//	return 0;
//}

//Divide two integers without using multiplication, division and mod operator.
//
//If it is overflow, return MAX_INT.