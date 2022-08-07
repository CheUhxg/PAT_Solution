#include <algorithm>
#include <iostream>
#include <vector>
#include <stdio.h>

#define MAX_DIS	0x3fffffff

using namespace std;

static vector<int> res, bikes;
static int c, n, sp, m, a, b, min_dis = MAX_DIS, min_send = MAX_DIS, min_back = MAX_DIS;

static void dfs(const vector<vector<int>>& g, const int now, const int dis, vector<int>& path) {
	if (now == sp) {
		int send = 0, back = 0;
		for (const int node : path) {
			if (bikes[node] > c / 2) {
				back += bikes[node] - c / 2;
			}
			else {
				if (back > c / 2 - bikes[node]) {
					back -= c / 2 - bikes[node];
				}
				else {
					send += c / 2 - bikes[node] - back;
					back = 0;
				}
			}
		}

		if (dis < min_dis) {
			min_dis = dis;
			min_send = send;
			min_back = back;
			res = path;
		}
		else if (dis == min_dis) {
			if (send < min_send) {
				min_send = send;
				min_back = back;
				res = path;
			}
			else if (send == min_send) {
				if (back < min_back) {
					min_back = back;
					res = path;
				}
			}
		}
		return;
	}
	for (int i = 1; i <= n; ++i) {
		if (find(path.begin(), path.end(), i) == path.end() && g[now][i] < MAX_DIS) {
			path.push_back(i);
			dfs(g, i, dis + g[now][i], path);
			path.pop_back();
		}
	}
}

//int main() {
//	cin >> c >> n >> sp >> m;
//	bikes.resize(n + 1);
//	vector<bool>visited(n + 1, false);
//	vector<vector<int>> g(n + 1, vector<int>(n + 1, MAX_DIS));
//	bikes[0] = 0;
//	visited[0] = true;
//	for (int i = 1; i <= n; ++i) {
//		cin >> bikes[i];
//	}
//	for (int i = 1; i <= m; ++i) {
//		cin >> a >> b;
//		cin >> g[a][b];
//		g[b][a] = g[a][b];
//	}
//	vector<int> path;
//	dfs(g, 0, 0, path);
//
//	cout << (min_send < 0 ? 0 : min_send) << ' ' << 0;
//	for (const int s : res) {
//		cout << "->" << s;
//	}
//	cout << ' ' << min_back << endl;
//}