#include <cstdio>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		vector<int> ans(2);
		map<int, int> numberToIndex;
		for (int index = 0; index < (int)numbers.size(); index++) {
			if (numberToIndex.find(numbers[index]) != numberToIndex.end()) {
				numberToIndex.erase(numbers[index]);
			}
			numberToIndex.insert(pair<int, int>(numbers[index], index));
		}
		for (int index1 = 0; index1 < (int)numbers.size(); index1++) {
			int another = target - numbers[index1];
			map<int, int>::iterator iter2 = numberToIndex.find(another);
			if (iter2 != numberToIndex.end() && index1 != iter2->second) {
				if (index1 < iter2->second) {
					ans[0] = index1 + 1;	// not zero-based, so +1
					ans[1] = iter2->second + 1;
				}
				else {
					ans[0] = iter2->second + 1;
					ans[1] = index1 + 1;
				}
				return ans;
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