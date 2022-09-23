#include <iostream>
#include <cstdio>

using namespace std;

//int main() {
//	int num[10] = { 0 };
//	int n, m, base, last = -1; cin >> n;
//	for (int i = 0; i < 4; ++i) {
//		++num[n % 10];
//		n /= 10;
//	}
//	while (true) {
//		n = m = 0;
//		base = 1;
//		for (int i = 9; i >= 0; --i) {
//			while (num[i]) {
//				--num[i];
//				n *= 10;
//				n += i;
//				m += base * i;
//				base *= 10;
//			}
//		}
//		if (n - m == last)break;
//		last = n - m;
//		printf("%04d - %04d = %04d\n", n, m, last);
//		n = last;
//		if (n == 0)break;
//		for (int i = 0; i < 4; ++i) {
//			++num[n % 10];
//			n /= 10;
//		}
//	}
//}