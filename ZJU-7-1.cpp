#include <iostream>
#include <vector>

using namespace std;

int ploy[100];

//int main() {
//	int n, a, top = 2; cin >> n >> a;
//	ploy[0] = a * -1;
//	ploy[1] = 1;
//	for (int i = 1; i < n; ++i) {
//		for (int j = top; j > 0; --j) {
//			ploy[j] = ploy[j - 1];
//		}
//		ploy[0] = 0;
//		cin >> a;
//		for (int j = 1; j <= top; ++j) {
//			ploy[j - 1] -= ploy[j] * a;
//		}
//		++top;
//	}
//	for (int j = top - 2; j >= 0; --j) {
//		cout << ploy[j] << ' ';
//	}
//}