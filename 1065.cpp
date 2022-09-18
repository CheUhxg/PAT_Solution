#include <iostream>

using namespace std;

int main() {
	int t; cin >> t;
	long long a, b, c, sum;
	for (int i = 1; i <= t; ++i) {
		cin >> a >> b >> c;
		sum = a + b;
		if (sum < 0) {
			if (a > 0 && b > 0)
				cout << "Case #" << i << ": " << "true";
			else
				cout << "Case #" << i << ": " << (sum > c ? "true" : "false");
		}
		else {
			if (a < 0 && b < 0)
				cout << "Case #" << i << ": " << "false";
			else
				cout << "Case #" << i << ": " << (sum > c ? "true" : "false");
		}
		if (i != t)cout << endl;
	}
}