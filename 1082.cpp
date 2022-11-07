#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const char* levelC[3] = {"Wan", "Yi"};
const char* mountC[4] = {"", "Shi", "Bai", "Qian"};
const char* numberC[10] = {
    "ling", "yi", "er", "san", "si",
    "wu", "liu", "qi", "ba", "jiu"
};

void readInChinese(vector<string>& res, int& num) {
    bool isAdd = false;
    for(int base = 0; base < 4; ++base) {
        if(num % 10) {
            isAdd = true;
            if(base > 0)res.emplace_back(mountC[base]);
            res.emplace_back(numberC[num % 10]);
        } else if(isAdd && num / 10 > 0) {
            res.emplace_back("ling");
            isAdd = false;
        }
        num /= 10;
    }
}

int main() {
    int num; cin >> num;
    if(num == 0) {
        cout << "ling" << endl;
        return 0;
    }
    vector<string> res;
    bool neg = num < 0;
    num = abs(num);
    for(auto & base : levelC) {
        readInChinese(res, num);
        if(num > 0 && num % 10000 > 0) {
            res.emplace_back(base);
        } else if(num > 0) {
            res.emplace_back("ling");
        } else {
            break;
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