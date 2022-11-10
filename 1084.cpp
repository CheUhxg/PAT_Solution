#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

struct Alpha {
    char c;
    int cnt = 0, pos = -1;
};

bool cmp(const Alpha& a1, const Alpha& a2) {
    return a1.pos < a2.pos;
}

int main() {
    string origin_str, real_str;
    getline(cin, origin_str);
    getline(cin, real_str);
    unordered_map<char, Alpha> count;
    for(int i = 0; i < origin_str.size(); ++i) {
        ++count[toupper(origin_str[i])].cnt;
        if(count[toupper(origin_str[i])].pos == -1) {
            count[toupper(origin_str[i])].pos = i;
            count[toupper(origin_str[i])].c = toupper(origin_str[i]);
        }
    }
    for(const char c : real_str) {
        --count[toupper(c)].cnt;
    }
    vector<Alpha>res;
    for(const auto & p : count) {
        if(p.second.cnt > 0) res.push_back(p.second);
    }
    sort(res.begin(), res.end(), cmp);
    for(const auto & a : res) {
        cout << a.c;
    }
    cout << endl;
}