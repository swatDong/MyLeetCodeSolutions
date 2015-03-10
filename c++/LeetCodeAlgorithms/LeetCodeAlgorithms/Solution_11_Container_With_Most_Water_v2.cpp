#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
	int maxArea(vector<int> &height) {
		int i = 0, j = height.size() - 1;
		int ans = 0;
		while (i < j)
		{
			int area = (j - i) * min(height[i], height[j]);
			ans = max(ans, area);
			if (height[i] <= height[j])
				i++;
			else
				j--;
		}
		return ans;
	}
};

//int main() {
//	vector<int> height = { 2, 3, 4, 6, 6, 3, 2, 2 };
//	Solution s;
//	printf("%d\n", s.maxArea(height));
//	return 0;
//}