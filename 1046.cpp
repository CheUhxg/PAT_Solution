#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n, m, big, small; cin >> n;
	vector<int> exits(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		cin >> exits[i];
		exits[i] += exits[i - 1];
	}
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> big >> small;
		if (small > big) swap(small, big);
		int d = exits[big - 1] - exits[small - 1];
		if (d * 2 > exits[n])cout << exits[n] - d << endl;
		else cout << d << endl;
	}
}