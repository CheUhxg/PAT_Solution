#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>

using namespace std;

bool cmp(const vector<int>& t1, const vector<int>& t2) {
	return t1[0] < t2[0];
}

int main() {
	int n, m, k, q;	cin >> n >> m >> k >> q;
	vector<vector<int>>take(k, vector<int>(2));
	vector<int> finish_time(k), end_time(n);
	for (int i = 0; i < k; ++i) {
		cin >> take[i][0];
		take[i][1] = i;
	}
	sort(take.begin(), take.end(), cmp);
	for (int i = 0; i < k; ++i) {
		if (i < n * m) {
			if (i < n)finish_time[take[i][1]] = take[i][0];
			else finish_time[take[i][1]] = take[i][0] + end_time[i % n];
			end_time[i % n] = finish_time[take[i][1]];
		}
		else {
			int index = 0;
			for (int j = 1; j < n; ++j) {
				if (end_time[index] > end_time[j]) {
					index = j;
				}
			}
			end_time[index] += take[i][0];
			finish_time[i] = end_time[index];
		}
	}
	for (int i = 0; i < q; ++i) {
		cin >> k;
		--k;
		n = finish_time[k] / 60;
		m = finish_time[k] % 60;
		if (n >= 9 && m > 0) {
			cout << "Sorry" << endl;
		}
		else {
			printf("%02d:%02d\n", n + 8, m);
		}
	}
}