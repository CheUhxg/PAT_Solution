#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int n, m, k, q;	cin >> n >> m >> k >> q;
	vector<int>take(k), finish_time(k);
	vector<queue<int>> queues(n, queue<int>());

	for (int i = 0; i < k; ++i) {
		cin >> take[i];
		if (i < n * m) {
			if (i < n)finish_time[i] = take[i];
			else finish_time[i] = take[i] + finish_time[i - n];
			queues[i % n].push(i);
		}
		else {
			int index = 0;
			for (int j = 1; j < n; ++j) {
				if (take[queues[j].front()] < take[queues[index].front()]) {
					index = j;
				}
			}
			finish_time[i] = take[i] + finish_time[queues[index].back()];
			queues[index].push(i);
			queues[index].pop();
		}
	}
	for (int i = 0; i < q; ++i) {
		cin >> k;
		--k;
		if (finish_time[k] - take[k] >= 540)
			cout << "Sorry" << endl;
		else
			printf("%02d:%02d\n", finish_time[k] / 60 + 8, finish_time[k] % 60);
	}
}