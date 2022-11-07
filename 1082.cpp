#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

const char* levelC[3] = {"Wan", "Yi"};
const char* mountC[4] = {"", "Shi", "Bai", "Qian"};
const char* numberC[10] = {
    "ling", "yi", "er", "san", "si",
    "wu", "liu", "qi", "ba", "jiu"
};

bool readInChinese(vector<string>& res, int& num) {
    bool isNull[4];
    for(int base = 0; base < 4; ++base) {
        isNull[base] = num % 10 == 0;
        if(num % 10) {
            if(base > 0)res.emplace_back(mountC[base]);
            res.emplace_back(numberC[num % 10]);
        }
        num /= 10;
    }
    return isNull[3] ||
           (isNull[2] && (!isNull[1] || !isNull[0])) ||
           (!isNull[2] && isNull[1] && !isNull[0]);
}

int main() {
    int num; cin >> num;
    vector<string> res;
    bool neg = num < 0, isZero;
    num = abs(num);
    for(auto & base : levelC) {
        if(num % 10000 > 0) isZero = readInChinese(res, num);
        if(num > 0) {
            if(isZero)res.emplace_back("ling");
            res.emplace_back(base);
        }
    }
    reverse(res.begin(), res.end());
    if(neg)cout << "Fu ";
    cout << res[0];
    for(int i = 1; i < res.size(); ++i) {
        if(!res[i].empty()) {
            cout << ' ' << res[i];
        }
    }
    cout << endl;
}