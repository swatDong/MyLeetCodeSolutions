#include <algorithm>
#include <unordered_set>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool checkAns4(unordered_set<string>& already, vector<int> &candidate) {
	string s = to_string(candidate[0]) + "=" + to_string(candidate[1]) + "=" + to_string(candidate[2]) + "=" + to_string(candidate[3]);
	if (already.find(s) != already.end()) {
		return false;
	}
	else {
		already.insert(s);
		return true;
	}
}

class Solution {
public:
	vector<vector<int>> fourSum(vector<int> &num, int target) {
		vector<vector<int>> ans;
		unordered_set<string> ansToString;

		int totalSize = num.size();
		vector<int> copyNumbers(totalSize);
		for (int index = 0; index < totalSize; index++) {
			copyNumbers[index] = num[index];
		}
		sort(copyNumbers.begin(), copyNumbers.end());

		int firstIndex = 0;
		int first;
		while (firstIndex < totalSize) {
			first = copyNumbers[firstIndex];
			int secondIndex = firstIndex + 1;
			int second;
			int threeTarget = target - first;
			while (secondIndex < totalSize) {
				second = copyNumbers[secondIndex];
				int begin = secondIndex + 1;
				int end = totalSize - 1;
				while (begin < end) {
					int t = second + copyNumbers[begin] + copyNumbers[end];
					if (t == threeTarget) {
						vector<int> ones = { first, second, copyNumbers[begin], copyNumbers[end] };
						if (checkAns4(ansToString, ones)) {
							ans.push_back(ones);
						}
						begin++;
						end--;
					}
					else if (t < threeTarget) {
						begin++;
					}
					else {
						end--;
					}
				}
				secondIndex++;
				while (secondIndex < totalSize && second == copyNumbers[secondIndex]) {
					secondIndex++;
				}
			}
			firstIndex++;
			while (firstIndex < totalSize && first == copyNumbers[firstIndex]) {
				firstIndex++;
			}
		}
		return ans;
	}
};

//int main() {
//	vector<int> numbers = { -2, 0, 1, 1, 2 };
//	Solution s;
//	vector<vector<int>> ans = s.fourSum(numbers, 0);
//	for (vector<int> a : ans) {
//		cout << a[0] << "," << a[1] << "," << a[2] << "," << a[3] << endl;
//	}
//	return 0;
//}

//Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target ? Find all unique quadruplets in the array which gives the sum of target.
//
//Note :
//	 Elements in a quadruplet(a, b, c, d) must be in non - descending order. (ie, a ¡Ü b ¡Ü c ¡Ü d)
//	 The solution set must not contain duplicate quadruplets.
//	 For example, given array S = { 1 0 - 1 0 - 2 2 }, and target = 0.
//
//	 A solution set is :
//(-1, 0, 0, 1)
//(-2, -1, 1, 2)
//(-2, 0, 0, 2)