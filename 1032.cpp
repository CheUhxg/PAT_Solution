#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main() {
	char c;
	int a, b, n, meet = -1; cin >> a >> b >> n;
	unordered_set<int>visited;
	for (int i = 0; i < n; ++i) {
		cin >> a >> c >> b;
		if (visited.count(b) > 0) meet = b;
		else visited.insert(b);
	}
	if (meet == -1) {
		cout << meet << endl;
	}
	else {
		printf("%05d\n", meet);
	}
}