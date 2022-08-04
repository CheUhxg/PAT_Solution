#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

struct Customer {
	int start, end, process;
};

bool cmp(const Customer& c1, const Customer& c2) {
	return c1.start < c2.start;
}

int main() {
	int n, k, hh, mm, ss, next = 0, now, cnt = 0; cin >> n >> k;
	char tmp;
	vector<Customer> customers(n);
	vector<int> windows(k, -1);
	for (int i = 0; i < n; ++i) {
		cin >> hh >> tmp >> mm >> tmp >> ss >> customers[i].process;
		customers[i].start = hh * 60 * 60 + mm * 60 + ss;
		if (customers[i].process > 60) customers[i].process = 60;
		customers[i].process *= 60;
	}
	sort(customers.begin(), customers.end(), cmp);
	for (int time = 28800; next < n && customers[next].start <= 61200; ++time) {
		for (int i = 0; i < k && next < n; ++i) {
			now = windows[i];
			if (now < 0) {
				if (customers[next].start <= 61200 && customers[next].start <= time) {
					cnt += time - customers[next].start;
					customers[next].end = time + customers[next].process;
					windows[i] = next++;
				}
				else if(customers[next].start > 61200)break;
			}
			else if (customers[now].end == time) {
				windows[i] = -1;
			}
		}
	}
	printf("%.1f\n", cnt / (60.0 * next));
}