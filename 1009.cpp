#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>

using namespace std;

static struct Poly {
	int N;
	double a;
};

static double m[2005];

//int main() {
//	vector<Poly> A;
//	int k, N, cnt = 0;
//	double a;
//
//	cin >> k;
//	while (k--) {
//		cin >> N >> a;
//		if (a == 0)continue;
//		A.push_back({ N, a });
//	}
//	cin >> k;
//	while (k--) {
//		cin >> N >> a;
//		if (a == 0)continue;
//		for (auto p : A) {
//			m[p.N + N] += p.a * a;
//		}
//	}
//	for (int i = 0; i <= 2000; ++i) {
//		if (m[i] != 0)++cnt;
//	}
//	cout << cnt;
//	for (int i = 2000; i >= 0; --i) {
//		if (m[i] != 0)
//			printf(" %d %.1f", i, m[i]);
//	}
//	cout << endl;
//}