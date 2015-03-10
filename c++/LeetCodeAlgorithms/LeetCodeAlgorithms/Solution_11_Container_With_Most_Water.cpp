#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

struct comparePoint{
	bool operator()(pair<int, int> p1, pair<int, int> p2) {
		return p1.second > p2.second;	//DESC
	}
};

class Solution {
public:
	int maxArea(vector<int> &height) {
		int len = height.size();
		bool *walked = new bool[len];
		priority_queue<pair<int, int>, vector<pair<int, int>>, comparePoint> points;
		for (int i = 0; i < len; i++) {
			walked[i] = false;
			points.push(pair<int, int>(i, height[i]));
		}
		int left = 0, right = len - 1;
		int ans = 0;
		while (!points.empty()) {
			pair<int, int> point = points.top();
			points.pop();
			int area = max(point.first - left, right - point.first) * point.second;
			if (area > ans) {
				ans = area;
			}
			walked[point.first] = true;
			while (left < len && walked[left]) left++;
			while (right >= 0 && walked[right]) right--;
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

//Given n non - negative integers a1, a2, ..., an, where each represents a point at coordinate(i, ai).n vertical lines are drawn such that the two endpoints of line i is at(i, ai) and(i, 0).Find two lines, which together with x - axis forms a container, such that the container contains the most water.
//
//Note: You may not slant the container.