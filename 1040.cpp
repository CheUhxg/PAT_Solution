#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

//int main() {
//	string origin; getline(cin, origin);
//	int size = origin.size(), max_len = 1;
//	vector<vector<bool>>dp(size, vector<bool>(size, false));
//	for (int i = 0; i < size; ++i) {
//		dp[i][i] = true;
//		if (i > 0 && origin[i] == origin[i - 1]) {
//			max_len = 2;
//			dp[i - 1][i] = true;
//		}
//	}
//	for (int len = 3; len <= size; ++len) {
//		for (int i = 0; i + len - 1 < size; ++i) {
//			if (origin[i] == origin[i + len - 1] && dp[i + 1][i + len - 2]) {
//				dp[i][i + len - 1] = true;
//				max_len = len;
//			}
//		}
//	}
//	cout << max_len << endl;
//}