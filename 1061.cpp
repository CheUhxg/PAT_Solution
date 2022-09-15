#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

//int main() {
//	string week[7] = { "MON ", "TUE ", "WED ", "THU ", "FRI ", "SAT ", "SUN " };
//	char cap, chr;
//	string s1, s2, s3, s4;
//	getline(cin, s1);
//	getline(cin, s2);
//	getline(cin, s3);
//	getline(cin, s4);
//
//	int i = 0;
//	for (; ; ++i) {
//		if (s1[i] == s2[i]) {
//			if (s1[i] >= 'A' && s1[i] <= 'G') {
//				cap = s1[i];
//				break;
//			}
//		}
//	}
//	++i;
//	for (; i < s1.size(); ++i) {
//		if (s1[i] == s2[i]) {
//			if (s1[i] >= 'A' && s1[i] <= 'N' || isdigit(s1[i])) {
//				chr = s1[i];
//				break;
//			}
//		}
//	}
//	i = 0;
//	for (; i < s3.size(); ++i) {
//		if (s3[i] == s4[i] && isalpha(s3[i])) {
//			break;
//		}
//	}
//	cout << week[cap - 'A'];
//	printf("%02d:%02d\n", isdigit(chr) ? chr - '0' : chr - 'A' + 10, i);
//}