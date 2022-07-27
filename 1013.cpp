#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

unordered_set<int> visited;

void dfs(const vector<vector<int>>& g, const int index) {
	for (int next : g[index]) {
		if (visited.count(next) == 0) {
			visited.insert(next);
			dfs(g, next);
		}
	}
}

//int main() {
//	int n, m, k, a, b; cin >> n >> m >> k;
//	vector<vector<int>> g(n + 1, vector<int>());
//	while(m--) {
//		cin >> a >> b;
//		g[a].push_back(b);
//		g[b].push_back(a);
//	}
//	int fa, cnt;
//	while (k--) {
//		cnt = 0;
//		visited.clear();
//		cin >> m;
//		visited.insert(m);
//		for (int i = 1; i <= n; ++i) {
//			if (visited.count(i) == 0) {
//				visited.insert(i);
//				dfs(g, i);
//				++cnt;
//			}
//		}
//		cout << cnt - 1 << endl;
//	}
//}