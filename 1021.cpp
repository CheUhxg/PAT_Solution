#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> res;
int n, max_depth;

int dfs(int index, vector<bool>& visited, const vector<vector<int>>& g) {
	int depth = 0, tmp;
	for (int i = 0; i < g[index].size(); ++i) {
		if (!visited[g[index][i]]) {
			visited[g[index][i]] = true;
			tmp = dfs(g[index][i], visited, g);
			visited[g[index][i]] = false;
			if (tmp > depth)depth = tmp;
		}
	}
	return depth + 1;
}

int main() {
	int a, b, cnt = 0, fa;
	cin >> n;
	vector<vector<int>>g(n + 1);
	vector<int> father(n + 1);
	for (int i = 1; i < n; ++i) {
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for (int i = 1; i <= n; ++i) {
		father[i] = i;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < g[i].size(); ++j) {
			if (i < g[i][j])
				fa = father[i];
			else
				fa = father[g[i][j]];
			while (fa != father[fa])fa = father[fa];
			father[i] = father[g[i][j]] = fa;
		}
	}
	fa = 0;
	for (int i = 1; i <= n; ++i) {
		if (father[i] > fa) {
			fa = father[i];
			++cnt;
		}
	}
	if (cnt > 1) {
		cout << "Error: " << cnt << " components\n";
		return 0;
	}
	vector<bool> visited(n + 1, false);
	for (int i = 1; i <= n; ++i) {
		visited[i] = true;
		cnt = dfs(i, visited, g);
		visited[i] = false;
		if (max_depth == cnt) {
			res.push_back(i);
		}
		else if (max_depth < cnt) {
			max_depth = cnt;
			res = { i };
		}
	}
	for (const int node : res) {
		cout << node << endl;
	}
}