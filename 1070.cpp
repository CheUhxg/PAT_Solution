#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Cake {
	int weight;
	double price;
};

bool cmp(const Cake& c1, const Cake& c2) {
	return c1.price / c1.weight > c2.price / c2.weight;
}

int main() {
	int n, d; cin >> n >> d;
	double cnt = 0;
	vector<Cake> cakes(n);
	for (int i = 0; i < n; ++i) {
		cin >> cakes[i].weight;
	}
	for (int i = 0; i < n; ++i) {
		cin >> cakes[i].price;
	}
	sort(cakes.begin(), cakes.end(), cmp);
	for (int i = 0; i < n; ++i) {
		if (d > cakes[i].weight) {
			d -= cakes[i].weight;
			cnt += cakes[i].price;
		}
		else {
			cnt += cakes[i].price / cakes[i].weight * d;
			break;
		}
	}
	printf("%.2f\n", cnt);
}