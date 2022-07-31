#include <algorithm>
#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

int main() {
	int n[3] = { 0 }, pos, low = 0, high = 0, a, b, c, dis, flag = 0;
	vector<char>s(20005, 0);
	cin >> n[0] >> n[1] >> n[2];
	for (int i = 0; i <= 2; ++i) {
		for (int j = 0; j < n[i]; ++j) {
			cin >> pos;
			s[pos + 10000] |= 1 << i;
			printf("%d\n", s[pos + 10000]);
		}
	}
	while (high <= 20000) {
		while (flag != 7 && high <= 20000) {
			if (s[high] > 0) {
				flag |= s[high];
			}
			++high;
		}
		while (low < high && s[low] == 0) ++low;

	}
	printf("MinD(%d, %d, %d) = %d", a, b, c, dis);
}