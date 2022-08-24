#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(const string& num1, const string& num2) {
	return num1 + num2 < num2 + num1;
}

int main() {
	int n; cin >> n;
	string res;
	vector<string> nums(n);
	for (int i = 0; i < n; ++i) {
		cin >> nums[i];
	}
	sort(nums.begin(), nums.end(), cmp);
	for (const string& num : nums) {
		res += num;
	}
	n = res.find_first_not_of('0');
	if (n == -1)cout << 0 << endl;
	else cout << res.substr(n) << endl;
}