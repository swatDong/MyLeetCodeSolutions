#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int> &num, int target) {
		int totalSize = num.size();
		vector<int> copyNumbers(totalSize);
		for (int index = 0; index < totalSize; index++) {
			copyNumbers[index] = num[index];
		}
		sort(copyNumbers.begin(), copyNumbers.end());

		int abs = 0;
		bool f = true;
		while (true) {
			int targett;
			if (f) {
				targett = target + abs;
				f = false;
				abs++;
			}
			else {
				targett = target - abs;
				f = true;
			}

			int curIndex = 0;
			int cur;
			while (curIndex < totalSize) {
				cur = copyNumbers[curIndex];
				int begin = curIndex + 1;
				int end = totalSize - 1;
				while (begin < end) {
					int t = cur + copyNumbers[begin] + copyNumbers[end];
					if (t == targett) {
						return targett;
						begin++;
						end--;
					}
					else if (t < targett) {
						begin++;
					}
					else {
						end--;
					}
				}
				curIndex++;
				while (curIndex < totalSize && cur == copyNumbers[curIndex]) {
					curIndex++;
				}
			}
		}
	}
};

//int main() {
//	vector<int> numbers = { 13, 2, 0, -14, -20, 19, 8, -5, -13, -3, 20, 15, 20, 5, 13, 14, -17, -7, 12, -6, 0, 20, -19, -1, -15, -2, 8, -2, -9, 13, 0, -3, -18, -9, -9, -19, 17, -14, -19, -4, -16, 2, 0, 9, 5, -7, -4, 20, 18, 9, 0, 12, -1, 10, -17, -11, 16, -13, -14, -3, 0, 2, -18, 2, 8, 20, -15, 3, -13, -12, -2, -19, 11, 11, -10, 1, 1, -10, -2, 12, 0, 17, -19, -7, 8, -19, -17, 5, -5, -10, 8, 0, -12, 4, 19, 2, 0, 12, 14, -9, 15, 7, 0, -16, -5, 16, -12, 0, 2, -16, 14, 18, 12, 13, 5, 0, 5, 6 };
//	int target = -59;
//	Solution s;
//	int ans = s.threeSumClosest(numbers, target);
//	printf("%d\n", ans);
//	return 0;
//}

//Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.Return the sum of the three integers.You may assume that each input would have exactly one solution.
//
//For example, given array S = { -1 2 1 - 4 }, and target = 1.
//
//The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).