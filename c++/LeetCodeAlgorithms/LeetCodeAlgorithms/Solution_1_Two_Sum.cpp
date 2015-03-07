#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		vector<int> ans(2);
		vector<int> copyNumbers(numbers.size());
		for (int index = 0; index < (int)numbers.size(); index++) {
			copyNumbers[index] = numbers[index];
		}
		sort(copyNumbers.begin(), copyNumbers.end());
		for (vector<int>::iterator iter = copyNumbers.begin(); iter != copyNumbers.end(); iter++) {
			int another = target - *iter;
			if (binary_search(iter + 1, copyNumbers.end(), another)) {
				bool a1 = false, a2 = false;
				int ans1, ans2;
				for (int index = 0; index < (int)numbers.size(); index++) {
					if (!a1) {
						if (*iter == numbers[index]) {
							ans1 = index;
							a1 = true;
						}
						else if (!a2 && another == numbers[index]) {
							ans2 = index;
							a2 = true;
						}
					}
					else if (!a2 && another == numbers[index]) {
						ans2 = index;
						a2 = true;
					}
					if (a1 && a2) {
						if (ans1 < ans2) {
							ans[0] = ans1 + 1;	// not zero-based, so +1
							ans[1] = ans2 + 1;
						}
						else {
							ans[0] = ans2 + 1;
							ans[1] = ans1 + 1;
						}
						return ans;
					}
				}
			}
		}
	}
};

//int main() {
//	vector<int> numbers = { 9, 3, 2, 7, 11 };
//	int target = 9;
//	Solution s;
//	vector<int> ans = s.twoSum(numbers, target);
//	printf("index1:%d, index2:%d\n", ans[0], ans[1]);
//	return 0;
//}

//Given an array of integers, find two numbers such that they add up to a specific target number.
//
//The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.Please note that your returned answers(both index1 and index2) are not zero - based.
//
//You may assume that each input would have exactly one solution.
//
//Input: numbers = { 2, 7, 11, 15 }, target = 9
//   Output : index1 = 1, index2 = 2