#include <iostream>
#include <vector>
#include <string>

using namespace std;

static inline char getChar(const string& s, int pos) {
    if(pos == s.size())return '\0';
    return s[s.size() - 1 - pos];
}

// int main() {
//     int n, len = 0; cin >> n; cin.get();
//     vector<string> str(n);
//     for(int i = 0; i < n; ++i) {
//         getline(cin, str[i]);
//     }
//     while(true) {
//         char c = getChar(str[0], len);
//         if(c == '\0')break;
//         int i;
//         for(i = 1; i < n; ++i) {
//             if(c != getChar(str[i], len)) break;
//         }
//         if(i < n)break;
//         ++len;
//     }
//     if(len > 0)cout << str[0].substr(str[0].size() - len) << endl;
//     else cout << "nai" << endl;
// }