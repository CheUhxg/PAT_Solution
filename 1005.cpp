#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

static unordered_map<char, string> um{
	{'1', "one"},
	{'2', "two"},
	{'3', "three"},
	{'4', "four"},
	{'5', "five"},
	{'6', "six"},
	{'7', "seven"},
	{'8', "eight"},
	{'9', "nine"},
	{'0', "zero"}
};

//int main() {
//	int n = 0;
//	string str;
//	getline(cin, str);
//	for (char c : str) {
//		n += c - '0';
//	}
//	if (n == 0) {
//		cout << "zero" << endl;
//		return 0;
//	}
//	str.clear();
//	while (n > 0) {
//		str.push_back(n % 10 + '0');
//		n /= 10;
//	}
//	for (int i = str.size() - 1; i >= 0; --i) {
//		if (i == 0) {
//			cout << um[str[i]] << endl;
//		}
//		else {
//			cout << um[str[i]] << ' ';
//		}
//	}
//}