#include<iostream>
#include<vector>

using namespace std;

//int main() {
//	int n, max_sum = -1, max_start = 0, max_end = 0, start = 0, sum = 0;
//	cin >> n;
//	vector<int> nums(n, 0);
//	for (int i = 0; i < n; ++i) {
//		cin >> nums[i];
//		if (sum >= 0) {
//			sum += nums[i];
//		}
//		else {
//			sum = nums[i];
//			start = i;
//		}
//		if (max_sum < sum) {
//			max_sum = sum;
//			max_start = start;
//			max_end = i;
//		}
//	}
//	if (max_sum >= 0) {
//		cout << max_sum << ' '
//			<< nums[max_start] << ' '
//			<< nums[max_end] << endl;
//	}
//	else {
//		cout << 0 << ' '
//			<< nums.front() << ' '
//			<< nums.back() << endl;
//	}
//}