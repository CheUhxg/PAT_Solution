#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n, m, l, pre, max_len = 0; cin >> n >> m;
	vector<int> priority(n + 1, 0x3fffffff);
	for (int i = 0; i < m; ++i) {
		cin >> l;
		priority[l] = i;
	}
	cin >> l;
	vector<int> given(l), dp(l, 0);
	for (int i = 0; i < l; ++i) {
		cin >> given[i];
	}
	for (int i = 0; i < l; ++i) {
		if (priority[given[i]] == 0x3fffffff)continue;
		pre = -1;
		for (int j = 0; j < i; ++j) {
			if (priority[given[j]] <= priority[given[i]]) {
				if (pre == -1 || dp[pre] < dp[j])pre = j;
			}
		}
		if (pre == -1)dp[i] = 1;
		else dp[i] = dp[pre] + 1;
		max_len = max(max_len, dp[i]);
	}
	cout << max_len << endl;
}