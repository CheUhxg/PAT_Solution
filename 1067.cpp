#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//int main() {
//	int n, cnt; cin >> n;
//	vector<int> n2i(n);
//	for (int i = 0; i < n; ++i) {
//		cin >> cnt;
//		n2i[cnt] = i;
//	}
//	cnt = 0;
//	for (int i = 1; i < n; ++i) {
//		while (i != n2i[i]) {
//			while (n2i[0] != 0) {
//				swap(n2i[0], n2i[n2i[0]]);
//				++cnt;
//			}
//			if (i != n2i[i]) {
//				swap(n2i[0], n2i[i]);
//				++cnt;
//			}
//		}
//	}
//	cout << cnt << endl;
//}