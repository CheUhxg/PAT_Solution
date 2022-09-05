#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

//int main() {
//	string s1, s2;
//	getline(cin, s1);
//	getline(cin, s2);
//	unordered_set<char> charInS2;
//	for (char c : s2) {
//		charInS2.insert(c);
//	}
//	int real = 0, index = 0;
//	while (index < s1.size()) {
//		if (charInS2.count(s1[index]) == 0) {
//			s1[real++] = s1[index];
//		}
//		++index;
//	}
//	s1.resize(real);
//	cout << s1 << endl;
//}