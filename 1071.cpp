#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

//int main() {
//	unordered_map<string, int> cnt;
//	string str, res;
//	getline(cin, str);
//	int low = 0, high = 0, max_cnt = 0;
//	while (high < str.size()) {
//		while (high < str.size() && (isalpha(str[high]) || isalnum(str[high])))++high;
//		string tmp(str.substr(low, high - low));
//		if (!tmp.empty()) {
//			for (char& c : tmp) {
//				c = tolower(c);
//			}
//			++cnt[tmp];
//		}
//		while (high < str.size() && !(isalpha(str[high]) || isalnum(str[high])))++high;
//		low = high;
//	}
//	for (const auto& p : cnt) {
//		if (p.second > max_cnt) {
//			max_cnt = p.second;
//			res = p.first;
//		}
//	}
//	cout << res << ' '
//		<< max_cnt << endl;
//}