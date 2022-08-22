#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Station {
	float price;
	int distance;
};

bool cmp(const Station& s1, const Station& s2) {
	return s1.price < s2.price;
}

int main() {
	float cost = 0.0;
	int cmax, dall, davg, n, cnow = 0; cin >> cmax >> dall >> davg >> n;
	vector<Station> stations(n);
	vector<bool> visited(dall, false);
	for (int i = 0; i < n; ++i) {
		cin >> stations[i].price >> stations[i].distance;
	}
	sort(stations.begin(), stations.end(), cmp);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; (j + stations[i].distance < dall) && (j < davg * cmax); ++j) {
			if (!visited[j + stations[i].distance]) {
				visited[j + stations[i].distance] = true;
				cost += stations[i].price / davg;
			}
		}
	}
	for (int i = 0; i < dall; ++i) {
		if (!visited[i]) {
			cost = 0;
			printf("The maximum travel distance = %.2f\n", i * 1.0);
			break;
		}
	}
	if (cost)printf("%.2f\n", cost);
}