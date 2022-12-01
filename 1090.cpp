#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int cnt, n;
double p, r, max_p;

void buy(int index, double price, const vector<int>&supp) {
    if(supp[index] == -1) {
        if(max_p < price * p) {
            max_p = price * p;
            cnt = 1;
        } else if(max_p == price * p) {
            ++cnt;
        }
        return;
    }
    buy(supp[index], price * (1 + r / 100), supp);
}

int main() {
    cin >> n >> p >> r;
    vector<int>supp(n);
    vector<bool>isSupp(n, false);
    for(int i = 0; i < n; ++i) {
        cin >> supp[i];
        if(supp[i] != -1)isSupp[supp[i]] = true;
    }
    for(int i = 0; i < n; ++i) {
        if(!isSupp[i])buy(i, 1.0, supp);
    }
    printf("%.2f %d\n", max_p, cnt);
}