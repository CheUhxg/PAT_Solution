#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

//int main() {
//	int n, m, k, q;	cin >> n >> m >> k >> q;
//	vector<int>take(k), finish_time(k);
//
//	for (int i = 0; i < k; ++i) {
//		cin >> take[i];
//		if (i < n * m) {
//			if (i < n)finish_time[i] = take[i];
//			else finish_time[i] = take[i] + finish_time[i - n];
//		}
//		else {
//			int index = i - n * m;
//			for (int j = 1; j < n; ++j) {
//				if (finish_time[i - n * m + j] < finish_time[index]) {
//					index = i - n * m + j;
//				}
//			}
//			finish_time[i] = take[i] + finish_time[index + n * (m - 1)];
//		}
//	}
//	for (int i = 0; i < q; ++i) {
//		cin >> k;
//		--k;
//		if (finish_time[k] - take[k] >= 540)
//			cout << "Sorry" << endl;
//		else
//			printf("%02d:%02d\n", finish_time[k] / 60 + 8, finish_time[k] % 60);
//	}
//}