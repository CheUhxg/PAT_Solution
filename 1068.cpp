#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m; cin >> n >> m;
	vector<int> coin(n);
	vector<vector<bool>> graph(n, vector<bool>(m + 1, 0));
	for (int i = 0; i < n; ++i) {
		cin >> coin[i];
	}
	sort(coin.begin(), coin.end(), greater<int>());
	vector<int> dp(m + 1, 0);
	for (int i = 0; i < n; ++i) {
		for (int j = m; j - coin[i] >= 0; --j) {
			if (dp[j - coin[i]] + coin[i] >= dp[j]) {
				graph[i][j] = true;
				dp[j] = dp[j - coin[i]] + coin[i];
			}
		}
	}
	if (dp[m] != m) {
		cout << "No Solution" << endl;
		return 0;
	}

	--n;
	vector<int> res;
	while (m > 0) {
		if (graph[n][m]) {
			res.push_back(coin[n]);
			m -= coin[n];
		}
		--n;
	}
	cout << res[0];
	for (int i = 1; i < res.size(); ++i) {
		cout << ' ' << res[i];
	}
	cout << endl;
}