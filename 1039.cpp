#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

//int main() {
//	int n, k, id, m; cin >> n >> k;
//	string name;
//	unordered_map<string, vector<int>> lists;
//	for (int i = 0; i < k; ++i) {
//		cin >> id >> m;
//		while (m--) {
//			cin >> name;
//			lists[name].push_back(id);
//		}
//	}
//	while (n--) {
//		cin >> name;
//		sort(lists[name].begin(), lists[name].end());
//		cout << name << ' ' << lists[name].size();
//		for (const int course : lists[name]) {
//			cout << ' ' << course;
//		}
//		cout << endl;
//	}
//}