#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

double sum = 0, r;

void dfs(int index, double rate,
         const vector<vector<int>>& tree) {
    if(tree[index][0] == 0) {
        sum += rate * tree[index][1];
        return;
    }
    for(int i = 0; i < tree[index].size(); ++i) {
        dfs(tree[index][i], rate * (1 + r), tree);
    }
}

int main() {
    int n, t;
    double p;
    cin >> n >> p >> r;
    r /= 100;
    vector<vector<int>> tree(n, vector<int>());
    for(int i = 0; i < n; ++i) {
        cin >> t;
        if(t > 0) {
            tree[i].resize(t);
            for(int j = 0; j < t; ++j) {
                cin >> tree[i][j];
            }
        } else {
            tree[i].resize(2);
            tree[i][0] = 0;
            cin >> tree[i][1];
        }
    }
    dfs(0, 1, tree);
    printf("%.1f\n", sum * p);
}