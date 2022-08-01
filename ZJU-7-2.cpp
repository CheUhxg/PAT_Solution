#include <algorithm>
#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

static int minD(int a, int b, int c) {
	return abs(a - b) + abs(a - c) + abs(b - c);
}

static void findD(const vector<int>& base, 
	const vector<int>& left,
	const vector<int>& right,
	int& a, int& b, int& c, int& dis, int pos) {
	int l, r, res;
	for (int i = base.size() - 1; i >= 0; --i) {
		l = lower_bound(left.begin(), left.end(), base[i]) - left.begin();
		r = upper_bound(right.begin(), right.end(), base[i]) - right.begin() - 1;
		if (l < left.size() &&
				r >= 0 &&
				(res = minD(base[i], left[l], right[r])) < dis) {
			dis = res;
			switch (pos) {
			case 1:
				a = base[i];
				b = left[l];
				c = right[r];
				break;
			case 2:
				a = left[l];
				b = base[i];
				c = right[r];
				break;
			case 3:
				a = left[l];
				b = right[r];
				c = base[i];
				break;
			}
		}
		l = upper_bound(left.begin(), left.end(), base[i]) - left.begin() - 1;
		r = lower_bound(right.begin(), right.end(), base[i]) - right.begin();
		if (l >= 0 &&
				r < right.size() &&
				(res = minD(base[i], left[l], right[r])) < dis) {
			dis = res;
			switch (pos) {
			case 1:
				a = base[i];
				b = left[l];
				c = right[r];
				break;
			case 2:
				a = left[l];
				b = base[i];
				c = right[r];
				break;
			case 3:
				a = left[l];
				b = right[r];
				c = base[i];
				break;
			}
		}
	}
}

//int main() {
//	vector<vector<int>> nums(3, vector<int>());
//	int n[3] = { 0 }, a, b, c, dis = 0x3fffffff;
//	cin >> n[0] >> n[1] >> n[2];
//	for (int i = 0; i <= 2; ++i) {
//		nums[i].resize(n[i]);
//		for (int j = 0; j < n[i]; ++j) {
//			cin >> nums[i][j];
//		}
//		sort(nums[i].begin(), nums[i].end());
//	}
//	findD(nums[0], nums[1], nums[2], a, b, c, dis, 1);
//	findD(nums[1], nums[0], nums[2], a, b, c, dis, 2);
//	findD(nums[2], nums[0], nums[1], a, b, c, dis, 3);
//	printf("MinD(%d, %d, %d) = %d", a, b, c, dis);
//}