#include <iostream>
#include <string>

using namespace std;

long long GetDecimal(const string& n, const int old_radix) {
	long long res = 0, base = 1;
	int num;
	for (int i = n.size() - 1; i >= 0; --i) {
		if (isdigit(n[i])) {
			num = n[i] - '0';
		}
		else {
			num = n[i] - 'a' + 10;
		}
		if (num >= old_radix) {
			return -1;
		}
		res += base * num;
		base *= old_radix;
		if (res < 0)return -1;
	}
	return res;
}

//int main() {
//	string n1, n2;
//	int tag, radix, num;
//	cin >> n1 >> n2 >> tag >> radix;
//	if (n1.compare(n2) == 0) {
//		cout << radix << endl;
//		return 0;
//	}
//	if (tag == 2)swap(n1, n2);
//	long long target, res;
//	if (radix == 10)
//		target = stoi(n1);
//	else
//		target = GetDecimal(n1, radix);
//
//	long long low = 2, high = target + 1, mid;
//	for (char c : n2) {
//		if (isdigit(c)) {
//			num = c - '0';
//		}
//		else {
//			num = c - 'a' + 10;
//		}
//		if (num + 1 > low)low = num + 1;
//	}
//
//	while(low <= high) {
//		mid = (low + high) / 2;
//		res = GetDecimal(n2, mid);
//		if (target < res || res < 0) {
//			high = mid - 1; 
//		}
//		else if (target > res) {
//			low = mid + 1;
//		}
//		else {
//			cout << mid << endl;
//			return 0;
//		}
//	}
//	cout << "Impossible" << endl;
//}