#include <iostream>
#include <vector>

using namespace std;

bool isPalin(const vector<int>& str) {
	for (int i = 0; 2 * i < str.size(); ++i) {
		if (str[i] != str[str.size() - i - 1]) {
			return false;
		}
	}
	return true;
}

int main() {
	int n, base; cin >> n >> base;
	vector<int> str;
	while (n > 0) {
		str.push_back(n % base);
		n /= base;
	}
	cout << (isPalin(str) ? "Yes" : "No") << endl;
	cout << str.back();
	for (int i = str.size() - 2; i >= 0; --i) {
		cout << ' ' << str[i];
	}
}