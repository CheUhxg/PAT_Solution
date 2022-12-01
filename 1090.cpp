#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>

using namespace std;

int cnt, n;
double p, r, max_p;
unordered_map<int, double>visited;

double buy(int index, double price, const vector<int>&supp) {
    if(supp[index] == -1 ||
        visited.count(supp[index]) > 0) {
        double more = supp[index] == -1?p:visited[supp[index]];
        if(max_p < price * more) {
            max_p = price * more;
            cnt = 1;
        } else if(max_p == price * more) {
            ++cnt;
        }
        return price * more;
    }
    double res = buy(supp[index], price * (1 + r / 100), supp);
    visited[supp[index]] = res / price;
    return res;
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