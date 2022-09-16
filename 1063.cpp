#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
	int n, m, k, nc, a, b; cin >> n;
	vector<vector<int>>sets(n, vector<int>());
	for (int i = 0; i < n; ++i) {
		cin >> m;
		sets[i].resize(m);
		for (int j = 0; j < m; ++j) {
			cin >> sets[i][j];
		}
	}
	unordered_map<int, bool> cnt;
	cin >> k;
	while (k--) {
		nc = 0;
		cnt.clear();
		cin >> a >> b;
		--a; --b;
		for (const int num : sets[a]) {
			cnt[num] = false;
		}
		for (const int num : sets[b]) {
			if (cnt.count(num) == 0)cnt[num] = true;
			else if (cnt[num] == false) {
				cnt[num] = true;
				++nc;
			}
		}
		printf("%.01f%\n", nc * 100.0 / cnt.size());
	}
}