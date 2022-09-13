#include <iostream>
#include <string>

using namespace std;

string convert(const int n, const string num) {
	int size = num.size(), i = 0, count = 0;
	string temp;
	for (; i < size && num[i] == '0'; ++i);
	if (num[i] == '.') {
		++i;
		for (; num[i] == '0'; ++i)--count;
		bool judge = false;	
		for (; temp.size() < n && i < size; ++i) {
			temp.push_back(num[i]);
			judge = true;
		}
		while (temp.size() < n)temp.push_back('0');
		if (!judge)count = 0;
	}
	else {
		for (int j = i; num[j] != '.' && j < size; ++j)++count;
		for (; num[i] != '.' && temp.size() < n && i < size; ++i)
			temp.push_back(num[i]);
		if (temp.size() < n)++i;
		for (; i < size && temp.size() < n; ++i)
			temp.push_back(num[i]);
		while (temp.size() < n)temp.push_back('0');
	}
	temp += ("*10^" + to_string(count));
	return temp;
}

int main() {
	int n;
	string num1, num2;
	cin >> n >> num1 >> num2;
	string res1 = convert(n, num1);
	string res2 = convert(n, num2);
	if (res1 == res2) cout << "YES 0." << res1 << endl;
	else cout << "NO 0." << res1 << " 0." << res2 << endl;
}