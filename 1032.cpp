#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <unordered_map>

using namespace std;

//int main() {
//	char c;
//	int sa, sb, a, b, n, meet; cin >> sa >> sb >> n;
//	unordered_map<int, int>next;
//	for (int i = 0; i < n; ++i) {
//		cin >> a >> c >> b;
//		next[a] = b;
//	}
//	vector<int> v1, v2;
//	while (sa >= 0) {
//		v1.push_back(sa);
//		sa = next[sa];
//	}
//	while (sb >= 0) {
//		v2.push_back(sb);
//		sb = next[sb];
//	}
//	for (meet = 1; meet <= v1.size() && meet <= v2.size() && v1[v1.size() - meet] == v2[v2.size() - meet]; ++meet);
//	if (meet == 1)cout << -1 << endl;
//	else printf("%05d\n", v1[v1.size() - meet + 1]);
//}