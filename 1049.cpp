#include <iostream>

using namespace std;

static int findOne(int n) {
	int high, low = 0, mid, res = 0, base = 1;
	while (n / base > 0) {
		high = n / base / 10;
		low = n % base;
		mid = n / base % 10;
		if (mid == 0)res += high * base;
		else if (mid == 1)res += high * base + low + 1;
		else res += (high + 1) * base;
		base *= 10;
	}
	return res;
}

//int main() {
//	int n; cin >> n;
//	cout << findOne(n) << endl;
//}