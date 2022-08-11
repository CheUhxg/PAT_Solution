#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

static int dfs(int index, int depth, vector<bool>& visited, const vector<vector<int>>& g) {
	visited[index] = true;
	int max_depth = depth;
	for (int i = 0; i < g[index].size(); ++i) {
		if (!visited[g[index][i]]) {
			max_depth = max(max_depth, dfs(g[index][i], depth + 1, visited, g));
		}
	}
	return max_depth;
}

//int main() {
//	int a, b, cnt = 1, min_degree = 0x3fffffff, n, max_cnt = 0;
//	cin >> n;
//	vector<vector<int>>g(n + 1);
//	vector<int> father(n + 1), in_degree(n + 1), res;
//	for (int i = 1; i < n; ++i) {
//		cin >> a >> b;
//		g[a].push_back(b);
//		g[b].push_back(a);
//		++in_degree[a];
//		++in_degree[b];
//	}
//	for (int i = 1; i <= n; ++i) {
//		father[i] = i;
//		min_degree = min(min_degree, in_degree[i]);
//		if (in_degree[i] < min_degree) {
//			min_degree = in_degree[i];
//		}
//	}
//	vector<bool> visited(n + 1, false);
//	dfs(1, 0, visited, g);
//	for (int i = 2; i <= n; ++i) {
//		if (!visited[i]) {
//			++cnt;
//			dfs(i, 0, visited, g);
//		}
//	}
//
//	if (cnt > 1) {
//		cout << "Error: " << cnt << " components\n";
//		return 0;
//	}
//
//	for (int i = 1; i <= n; ++i) {
//		if (in_degree[i] == min_degree) {
//			visited.clear();
//			visited.resize(n + 1, false);
//			cnt = dfs(i, 0, visited, g);
//			if (max_cnt == cnt) {
//				res.push_back(i);
//			}
//			else if (max_cnt < cnt) {
//				max_cnt = cnt;
//				res = { i };
//			}
//		}
//	}
//	sort(res.begin(), res.end(), less<int>());
//	for (const int node : res) {
//		cout << node << endl;
//	}
//}