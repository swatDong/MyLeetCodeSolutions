#include <algorithm>
#include <unordered_set>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool checkAns(unordered_set<string>& already, vector<int> &candidate) {
	string s = to_string(candidate[0]) + "=" + to_string(candidate[1]) + "=" + to_string(candidate[2]);
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
	vector<vector<int>> threeSum(vector<int> &num) {
		vector<vector<int>> ans;
		unordered_set<string> ansToString;

		int totalSize = num.size();
		vector<int> copyNumbers(totalSize);
		for (int index = 0; index < totalSize; index++) {
			copyNumbers[index] = num[index];
		}
		sort(copyNumbers.begin(), copyNumbers.end());

		int curIndex = 0;
		int cur;
		while (curIndex < totalSize) {
			cur = copyNumbers[curIndex];
			if (cur > 0) {
				break;
			}
			int begin = curIndex + 1;
			int end = totalSize - 1;
			while (begin < end) {
				int t = cur + copyNumbers[begin] + copyNumbers[end];
				if (t == 0) {
					vector<int> ones = { cur, copyNumbers[begin], copyNumbers[end] };
					if (checkAns(ansToString, ones)) {
						ans.push_back(ones);
					}
					begin++;
					end--;
				}
				else if (t < 0) {
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
		return ans;
	}
};

//int main() {
//	vector<int> numbers = { -2, 0, 1, 1, 2 };
//	Solution s;
//	vector<vector<int>> ans = s.threeSum(numbers);
//	for (vector<int> a : ans) {
//		cout << a[0] << "," << a[1] << "," << a[2] << endl;
//	}
//	return 0;
//}

//Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0 ? Find all unique triplets in the array which gives the sum of zero.
//
//Note :
//	 Elements in a triplet(a, b, c) must be in non - descending order. (ie, a ¡Ü b ¡Ü c)
//	 The solution set must not contain duplicate triplets.
//	 For example, given array S = { -1 0 1 2 - 1 - 4 },
//
//	 A solution set is :
//(-1, 0, 1)
//(-1, -1, 2)