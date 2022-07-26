#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main() {
	const char m[4] = "WTL";
	double profit = 0.65, tmp;
	for (int i = 0; i < 3; ++i) {
		double max_game = 0;
		int res = 0;
		for (int j = 0; j < 3; ++j) {
			cin >> tmp;
			if (tmp > max_game) {
				max_game = tmp;
				res = j;
			}
		}
		cout << m[res] << ' ';
		profit *= max_game;
	}
	printf("%.2f\n", (profit - 1) * 2);
}