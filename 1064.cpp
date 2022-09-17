#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getLeft(int size) {
	int base = 1;
	while ((base - 1) * 2 <= size) {
		base *= 2;
	}
	base /= 2;
	size -= (base - 1) * 2;
	if (base - 1 + size >= base * 2 - 1)return base * 2 - 1;
	else return base - 1 + size;
}

void getRes(int index, int start, int len, vector<int>& res, const vector<int>& nums) {
	if (index > nums.size() || len == 0)return;
	if (len == 1) {
		res[index] = nums[start];
		return;
	}
	int left = getLeft(len - 1);
	res[index] = nums[start + left];
	getRes(index * 2 + 1, start, left, res, nums);
	getRes(index * 2 + 2, start + left + 1, len - left - 1, res, nums);
}

int main() {
	int n; cin >> n;
	vector<int>nums(n), res(n);
	for (int i = 0; i < n; ++i) {
		cin >> nums[i];
	}
	sort(nums.begin(), nums.end());
	getRes(0, 0, n, res, nums);
	cout << res[0];
	for (int i = 1; i < n; ++i) {
		cout << ' ' << res[i];
	}
	cout << endl;
}