#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

static struct Cake {
	double price, weight;
};

static bool cmp(const Cake& c1, const Cake& c2) {
	return c1.price / c1.weight > c2.price / c2.weight;
}

//int main() {
//	double d;
//	int n; cin >> n >> d;
//	double cnt = 0;
//	vector<Cake> cakes(n);
//	for (int i = 0; i < n; ++i) {
//		cin >> cakes[i].weight;
//	}
//	for (int i = 0; i < n; ++i) {
//		cin >> cakes[i].price;
//	}
//	sort(cakes.begin(), cakes.end(), cmp);
//	for (int i = 0; i < n; ++i) {
//		if (d > cakes[i].weight) {
//			d -= cakes[i].weight;
//			cnt += cakes[i].price;
//		}
//		else {
//			cnt += cakes[i].price / cakes[i].weight * d;
//			break;
//		}
//	}
//	printf("%.2f\n", cnt);
//}