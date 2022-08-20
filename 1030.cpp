#include <iostream>
#include <vector>
#include <algorithm>

#define INF 0x3fffffff

using namespace std;

struct City
{
	int destin, cost, length;
};

vector<int> res;
int n, m, s, d, min_length = INF, min_cost = INF;

void dfs(const int start, const int length, const int cost,
				const vector<vector<City>> g, vector<bool>& visited, vector<int>& path) {
	path.push_back(start);
	if (start == d) {
		if (length < min_length) {
			min_length = length;
			min_cost = cost;
			res = path;
		}
		else if (length == min_length) {
			if (cost < min_cost) {
				min_cost = cost;
				res = path;
			}
		}
		path.pop_back();
		return;
	}
	visited[start] = true;
	for (const City& c : g[start]) {
		if (!visited[c.destin]) {
			dfs(c.destin, length + c.length, cost + c.cost, g, visited, path);
		}
	}
	visited[start] = false;
	path.pop_back();
}

int main() {
	int c1, c2, length, cost, mid; cin >> n >> m >> s >> d;
	vector<vector<City>> g(n);
	for (int i = 0; i < m; ++i) {
		cin >> c1 >> c2 >> length >> cost;
		g[c1].push_back({ c2, cost, length });
		g[c2].push_back({ c1, cost, length });
	}
	vector<int>path;
	vector<bool>visited(n, false);
	dfs(s, 0, 0, g, visited, path);
	for (const int node : res) {
		cout << node << ' ';
	}
	cout << min_length << ' ' << min_cost << endl;
}