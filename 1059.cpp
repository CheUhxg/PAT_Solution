#include <iostream>
#include <map>

using namespace std;

int main() {
	long int n, tmp; cin >> n;
	map<int, int> cnt;
	cout << n << '=';
	for (int i = 2; n > 1; ++i) {
		while (n % i == 0) {
			++cnt[i];
			n /= i;
		}
	}
	for (auto iter = cnt.begin();
		iter != cnt.end();
		) {
		cout << iter->first;
		if (iter->second > 1) {
			cout << '^' << iter->second;
		}
		if (++iter != cnt.end()) {
			cout << '*';
		}
	}
	cout << endl;
}