#include <algorithm>
#include <iostream>
#include <vector>
#include <stdio.h>

#define MAX_DIS	0x3fffffff

using namespace std;

vector<int> res, bikes;
int c, n, sp, m, a, b, min_dis = MAX_DIS, min_send = MAX_DIS, min_back = MAX_DIS;

void dfs(const vector<vector<int>>& g, const int now, const int dis, const int sum, vector<int>& path) {
	if (now == sp) {
		int send;
		if (sum >= path.size() * c / 2) {
			send = 0;
		}
		else {
			send = path.size() * c / 2 - sum;
		}
		if (dis < min_dis) {
			min_dis = dis;
			min_send = send;
			min_back = sum + send - path.size() * c / 2;
			res = path;
		}
		else if (dis == min_dis) {
			if (send < min_send) {
				min_send = send;
				min_back = sum + send - path.size() * c / 2;
				res = path;
			}
			else if (send == min_send) {
				if (sum - path.size() * c / 2 < min_back) {
					min_back = sum + send - path.size() * c / 2;
					res = path;
				}
			}
		}
		return;
	}
	for (int i = 1; i <= n; ++i) {
		if (find(path.begin(), path.end(), i) == path.end() && g[now][i] < MAX_DIS) {
			path.push_back(i);
			dfs(g, i, dis + g[now][i], sum + bikes[i], path);
			path.pop_back();
		}
	}
}

int main() {
	cin >> c >> n >> sp >> m;
	bikes.resize(n + 1);
	vector<bool>visited(n + 1, false);
	vector<vector<int>> g(n + 1, vector<int>(n + 1, MAX_DIS));
	bikes[0] = 0;
	visited[0] = true;
	for (int i = 1; i <= n; ++i) {
		cin >> bikes[i];
	}
	for (int i = 1; i <= m; ++i) {
		cin >> a >> b;
		cin >> g[a][b];
		g[b][a] = g[a][b];
	}
	vector<int> path;
	dfs(g, 0, 0, 0, path);

	cout << min_send << ' ' << 0;
	for (const int s : res) {
		cout << "->" << s;
	}
	cout << ' ' << min_back << endl;
}