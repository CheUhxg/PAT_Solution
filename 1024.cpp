#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

bool isPalin(string n) {
	for (int i = 0; i < n.size() / 2;++i) {
		if (n[i] != n[n.size() - i - 1])return false;
	}
	return true;
}

void changeN(string& n) {
	string tmp(n);
	int add = 0, num;
	for (int i = 0; i < n.size(); ++i) {
		num = add + n[i] + tmp[tmp.size() - i - 1] - '0' * 2;
		n[i] = num % 10 + '0';
		add = num / 10;
	}
	if (add > 0) {
		n.push_back('1');
	}
}

int main() {
	string n;
	int k, i;
	cin >> n >> k;
	reverse(n.begin(), n.end());
	for (i = 0; i < k; ++i) {
		if (isPalin(n))break;
		changeN(n);
	}
	reverse(n.begin(), n.end());

	cout << n << endl
		<< i << endl;
}