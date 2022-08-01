#include <iostream>
#include <string>

using namespace std;

static int parse(int n, const int d) {
	int res = 0;

	while (n > 0) {
		res *= d;
		res += n % d;
		n /= d;
	}

	return res;
}

static bool isPrime(const int d) {
	if (d <= 1)return false;
	for (int i = 2; i * i <= d; ++i) {
		if (d % i == 0)
			return false;
	}
	return true;
}

//int main() {
//	int n, d;
//	while (cin >> n && n > 0) {
//		cin >> d;
//		if (!isPrime(n)) {
//			cout << "No" << endl;
//			continue;
//		}
//		n = parse(n, d);
//		cout << (isPrime(n) ? "Yes" : "No") << endl;
//	}
//}