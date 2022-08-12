#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

//int main() {
//	int n, d, cnt = 0; cin >> n >> d;
//	vector<int> item(n), coupon(n);
//	for (int i = 0; i < n; ++i) {
//		cin >> item[i];
//	}
//	for (int i = 0; i < n; ++i) {
//		cin >> coupon[i];
//	}
//	sort(item.begin(), item.end());
//	sort(coupon.begin(), coupon.end());
//	for (int i = n - 2; i >= 0; --i) {
//		if (i < n - 1) {
//			coupon[i] += coupon[i + 1];
//		}
//	}
//	for (int i = 0; i < n; ++i) {
//		for (int j = n; j >= 1; --j) {
//			if (item[i] * j - coupon[n - j] < d) {
//				d -= item[i] * j - coupon[n - j];
//				cnt += j;
//				break;
//			}
//		}
//	}
//	cout << cnt << ' ' << d << endl;
//}