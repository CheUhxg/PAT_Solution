#include <iostream>
#include <string>

using namespace std;

//int main() {
//	string num; getline(cin, num);
//	int D_index = num.find_first_of('.');
//	int E_index = num.find_last_of('E');
//	int times = stoi(num.substr(E_index + 1));
//
//	if (num[0] == '-')cout << '-';
//	if (times < 0) {
//		cout << "0.";
//		for (int i = 0; i < abs(times) - 1; ++i)cout << '0';
//		for (int i = 1; i < E_index; ++i) {
//			if (isalnum(num[i]))cout << num[i];
//		}
//	}
//	else {
//		int cnt, i;
//		for (i = 1, cnt = -1; i < E_index && cnt < times; ++i) {
//			if (isalnum(num[i])) {
//				cout << num[i];
//				++cnt;
//			}
//		}
//		if (i == E_index) {
//			for (int j = 0; j < times - cnt; j++) cout << '0';
//		}
//		else {
//			cout << '.';
//			for (int j = i; j < E_index; ++j) cout << num[j];
//		}
//	}
//}