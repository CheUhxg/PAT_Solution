#include<iostream>
#include<vector>
#include<map>

using namespace std;

static short max_layer;

static void dfs(const vector<vector<short>>& sons, map<short, short>& res, const short index, const short layer) {
	if (layer > max_layer)max_layer = layer;
	if (sons[index].size() == 0) {
		++res[layer];
		return;
	}
	for (short next : sons[index]) {
		dfs(sons, res, next, layer + 1);
	}
}

//int main() {
//	short n, m, root, k, child;
//	while (cin >> n && n) {
//		max_layer = 0;
//		vector<vector<short>> sons(n + 1, vector<short>());
//		cin >> m;
//		while (m--) {
//			cin >> root >> k;
//			while (k--) {
//				cin >> child;
//				sons[root].push_back(child);
//			}
//		}
//		cout << '0';
//		if (sons[1].size() > 0) {
//			map<short, short> res;
//			dfs(sons, res, 1, 0);
//			for (short i = 1; i <= max_layer; ++i) {
//				if (res.count(i) > 0)
//					cout << ' ' << res[i];
//				else
//					cout << ' ' << 0;
//			}
//		}
//		cout << endl;
//	}
//}