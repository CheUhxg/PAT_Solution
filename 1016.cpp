#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stdio.h>

using namespace std;

struct Record {
	string name, time;
	bool on;
};

static bool cmp(const Record& r1, const Record& r2) {
	int res = r1.name.compare(r2.name);
	if (res == 0)
		return r1.time.compare(r2.time) < 0;
	return res < 0;
}

static void getTime(const string& time, int& d, int& h, int& m) {
	d = stoi(time.substr(3, 5));
	h = stoi(time.substr(6, 8));
	m = stoi(time.substr(9, 11));
}

//int main() {
//	int cost[24], n;
//	for (int i = 0; i < 24; ++i) {
//		cin >> cost[i];
//	}
//	cin >> n; cin.get();
//	vector<Record> records(n);
//	string status, mon;
//	for (int i = 0; i < n; ++i) {
//		cin >> records[i].name
//			>> records[i].time
//			>> status;
//		cin.get();
//		if (status.compare("on-line") == 0) records[i].on = true;
//		else records[i].on = false;
//	}
//	mon = records[0].time.substr(0, 2);
//	sort(records.begin(), records.end(), cmp);
//	map<string, vector<string>> res;
//	for (int i = 1; i < n; ++i) {
//		if (!records[i].on &&
//			records[i].name.compare(records[i - 1].name) == 0 &&
//			records[i - 1].on
//			) {
//			res[records[i].name].push_back(records[i - 1].time);
//			res[records[i].name].push_back(records[i].time);
//		}
//	}
//	int d1, d2, h1, h2, m1, m2, cnt;
//	float sum, once;
//	for (const auto& p : res) {
//		sum = 0;
//		cout << p.first << ' ' << mon << endl;
//		for (int i = 0; i < p.second.size(); i += 2) {
//			once = 0;
//			getTime(p.second[i], d1, h1, m1);
//			getTime(p.second[i + 1], d2, h2, m2);
//			cnt = (d2 - d1) * 24 * 60 + (h2 - h1) * 60 + (m2 - m1);
//			cout << p.second[i].substr(3) << ' '
//				<< p.second[i + 1].substr(3) << ' '
//				<< cnt << ' ';
//			while (d1 < d2 || h1 < h2) {
//				once += cost[h1] * (60 - m1);
//				if (++h1 >= 24) {
//					h1 = 0;
//					++d1;
//				}
//				m1 = 0;
//			}
//			once += cost[h1] * (m2 - m1);
//			once /= 100.0;
//			printf("$%.2f\n", once);
//			sum += once;
//		}
//		printf("Total amount: $%.2f\n", sum);
//	}
//}