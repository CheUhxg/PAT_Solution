#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//int main() {
//	string str; getline(cin, str);
//	int length = str.size(), v = 0, h, tmp;
//	for (h = 3; h <= length; ++h) {
//		tmp = (length + 2 - h) / 2;
//		if (tmp * 2 == length + 2 - h && tmp <= h) {
//			v = max(v, tmp);
//		}
//	}
//	--v;
//	h = length - 2 * v;
//	for (tmp = 0; tmp < v; ++tmp) {
//		cout << str[tmp];
//		for (int j = 0; j < h - 2;++j) {
//			cout << ' ';
//		}
//		cout << str[length - 1 - tmp] << endl;
//	}
//	for (int i = 0; i < h; ++i) {
//		cout << str[tmp + i];
//	}
//}