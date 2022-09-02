#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

static vector<string> student;

static bool cmp(const int a, const int b) {
	return student[a] < student[b];
}

//int main() {
//	int n, k, m, c; cin >> n >> k;
//	vector<vector<int>> course(k + 1, vector<int>());
//	student.resize(n);
//	for (int i = 0; i < n; ++i) {
//		cin >> student[i] >> m;
//		while (m--) {
//			cin >> c;
//			course[c].push_back(i);
//		}
//	}
//	for (int i = 1; i <= k; ++i) {
//		sort(course[i].begin(), course[i].end(), cmp);
//		cout << i << ' ' << course[i].size() << endl;
//		for (const int& id : course[i]) {
//			printf("%s\n", student[id].c_str());
//		}
//	}
//}