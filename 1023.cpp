#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

//int main() {
//	int add = 0, n, table[10] = { 0 };
//	string num;
//	getline(cin, num);
//	for (int i = num.size() - 1; i >= 0; --i) {
//		++table[num[i] - '0'];
//		n = (num[i] - '0') * 2 + add;
//		num[i] = n % 10 + '0';
//		add = n / 10;
//		--table[num[i] - '0'];
//	}
//	if (add == 0) {
//		for (const int d : table) {
//			if (d) {
//				add = 1;
//				break;
//			}
//		}
//		if (add == 0) {
//			cout << "Yes" << endl
//				<< num << endl;
//			return 0;
//		}
//		add = 0;
//	}
//	cout << "No" << endl;
//	if(add == 1)cout << add;
//	cout << num << endl;
//}