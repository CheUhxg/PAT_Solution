#include<iostream>
#include<algorithm>
#include<vector>

#define INF 0x3fffffff

using namespace std;

int n, m, c1, c2, s, e, dis;
vector<int> rescues, max_num, path;

void dijkstra(const vector<vector<int>>& graph) {
	vector<bool>visited(n, false);
	vector<int>distance(n, INF);
	distance[c1] = 0;
	max_num[c1] = rescues[c1];
	path[c1] = 1;

	for (int i = 0; i < n; ++i) {
		int close = 0, min_dis = INF;
		for (int j = 0; j < n; ++j) {
			if (!visited[j] && distance[j] < min_dis) {
				close = j;
				min_dis = distance[j];
			}
		}
		visited[close] = true;
		for (int j = 0; j < n; ++j) {
			if (!visited[j] && distance[j] >= distance[close] + graph[close][j]) {
				if (distance[j] == distance[close] + graph[close][j]) {
					path[j] += path[close];
					if (max_num[j] < max_num[close] + rescues[j]) {
						max_num[j] = max_num[close] + rescues[j];
					}
				}
				else {
					distance[j] = distance[close] + graph[close][j];
					path[j] = path[close];
					max_num[j] = max_num[close] + rescues[j];
				}
			}
		}
	}
}

//int main() {
//	cin >> n >> m >> c1 >> c2;
//	rescues.resize(n);
//	path.resize(n);
//	max_num.resize(n);
//	vector<vector<int>> graph(n, vector<int>(n, INF));
//	for (int i = 0; i < n; ++i)cin >> rescues[i];
//	for (int i = 0; i < m; ++i) {
//		cin >> s >> e >> dis;
//		graph[s][e] = dis;
//		graph[e][s] = dis;
//	}
//	dijkstra(graph);
//
//	cout << path[c2] << ' ' << max_num[c2] << endl;
//}