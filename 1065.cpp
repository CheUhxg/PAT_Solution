#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	int t; cin >> t;
	bool res;
	long long a, b, c, sum;
	for (int i = 1; i <= t; ++i) {
		scanf("%lld %lld %lld", &a, &b, &c);
		sum = a + b;
		if (a > 0 && b > 0 && sum < 0) res = true;
		else if (a < 0 && b < 0 && sum >= 0) res = false;
		else if (sum > c) res = true;
		else res = false;

		if(res)
			cout << "Case #" << i << ": " << "true";
		else
			cout << "Case #" << i << ": " << "false";
		if (i != t)cout << endl;
	}
}