#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

char getCard(int& num) {
	int tmp(num);
	num = (num - 1) % 13 + 1;
	switch ((tmp - 1) / 13) {
	case 0:
		return 'S';
	case 1:
		return 'H';
	case 2:
		return 'C';
	case 3:
		return 'D';
	default:
		return 'J';
	}
}

int main() {
	int position[55] = { 0 }, res[55] = { 0 }, tmp[55] = { 0 };
	int k, n; cin >> k;
	for (int i = 1; i <= 54; ++i) {
		cin >> n;
		position[n] = i;
		res[n] = i;
	}
	int* prev = res, * next = tmp, * p;
	while (--k) {
		for (int i = 1; i <= 54; ++i) {
			next[i] = prev[position[i]];
		}
		p = next;
		next = prev;
		prev = p;
	}
	cout << getCard(prev[1]) << prev[1];
	for (int i = 2; i <= 54; ++i) {
		cout << ' ' << getCard(prev[i]) << prev[i];
	}
	cout << endl;
}