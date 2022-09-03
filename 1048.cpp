#include <iostream>
#include <algorithm>

using namespace std;

static int cnt[505];

//int main() {
//	int n, m, value, a = 0, b = 0; cin >> n >> m;
//	while (n--) {
//		cin >> value;
//		++cnt[value];
//	}
//	for (int i = 1; i * 2 <= m; ++i) {
//		if (m - i <= 500 && cnt[i] > 0 && cnt[m - i] > 0) {
//			if (i * 2 == m && cnt[i] > 1 || i * 2 < m) {
//				a = i;
//				b = m - i;
//				break;
//			}
//		}
//	}
//	if (a > 0)cout << a << ' ' << b << endl;
//	else cout << "No Solution" << endl;
//}