#include<iostream>
#include<algorithm>
#include<string>
#include<cstdio>

using namespace std;

static char convert(int num) {
	if (num < 10) {
		return num + '0';
	}
	else {
		return num + 'A' - 10;
	}
}

//int main() {
//	int rgb[3];
//	string res;
//	cin >> rgb[0] >> rgb[1] >> rgb[2];
//	for (int i = 2; i >= 0; --i) {
//		for (int j = 0; j < 2; ++j) {
//			res.push_back(convert(rgb[i] % 13));
//			rgb[i] /= 13;
//		}
//	}
//	res.push_back('#');
//	reverse(res.begin(), res.end());
//	cout << res << endl;
//}