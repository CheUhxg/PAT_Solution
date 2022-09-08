#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

static struct Node {
	int w;
	vector<int> sons;
};

static vector<vector<int>> res;

static void dfs(const int index, const int weight, const vector<Node>& tree, vector<int>& path) {
	if (tree[index].sons.size() == 0) {
		if (tree[index].w == weight) {
			res.push_back(path);
			for (int& node : res.back()) {
				node = tree[node].w;
			}
		}
		return;
	}
	for (const int son : tree[index].sons) {
		if (find(path.begin(), path.end(), son) == path.end() && tree[son].w <= weight) {
			path.push_back(son);
			dfs(son, weight - tree[index].w, tree, path);
			path.pop_back();
		}
	}
}

static bool cmp(const vector<int>& v1, const vector<int>& v2) {
	return v1 > v2;
}

//int main() {
//	int n, m, s, id, num, root = 0; cin >> n >> m >> s;
//	vector<Node> tree(n);
//	vector<bool> visited(n, false);
//	for (int i = 0; i < n; ++i) {
//		cin >> tree[i].w;
//	}
//	for (int i = 0; i < m; ++i) {
//		cin >> id >> num;
//		tree[id].sons.resize(num);
//		for (int j = 0; j < num; ++j) {
//			cin >> tree[id].sons[j];
//			visited[tree[id].sons[j]] = true;
//		}
//	}
//	while (visited[root])++root;
//	vector<int> path;
//	dfs(root, s, tree, path);
//	sort(res.begin(), res.end(), cmp);
//	for (const vector<int>& v : res) {
//		cout << tree[root].w;
//		for (int i = 0; i < v.size(); ++i) {
//			cout << ' ' << v[i];
//		}
//		cout << endl;
//	}
//}