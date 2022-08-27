#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
	int n; cin >> n;
	vector<int> nums(n);
	unordered_map<int, int> visited;
	for (int i = 0; i < n; ++i) {
		cin >> nums[i];
		++visited[nums[i]];
	}
	n = -1;
	for (const int num : nums) {
		if (visited[num] == 1) {
			n = num;
			break;
		}
	}
	if (n == -1) cout << "None" << endl;
	else cout << n << endl;
}