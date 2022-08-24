#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(const string& num1, const string& num2) {
	int index = 0;
	while (index < num1.size() && index < num2.size()) {
		if (num1[index] != num2[index])return num1[index] < num2[index];
		++index;
	}
	if (index < num1.size()) return cmp(num1.substr(index), num2);
	if (index < num2.size()) return cmp(num1, num2.substr(index));
	return true;
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