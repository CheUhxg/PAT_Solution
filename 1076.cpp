#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

int bfs(int id, int layer,
         const vector<vector<int>>& follower) {
    unordered_set<int> visited;
    queue<int> q;
    visited.insert(id);
    q.push(id);
    while(!q.empty() && layer--) {
        int len = q.size();
        while(len--) {
            id = q.front();
            q.pop();
            for(int next : follower[id]) {
                if(visited.count(next) == 0) {
                    visited.insert(next);
                    q.push(next);
                }
            }
        }
    }
    return visited.size() - 1;
}

int main() {
    int n, l, k, id; cin >> n >> l;
    vector<vector<int>> follower(n + 1);
    for(int i = 1; i <= n; ++i) {
        int totle, follow;
        cin >> totle;
        while(totle--) {
            cin >> follow;
            follower[follow].push_back(i);
        }
    }
    cin >> k;
    while(k--) {
        int last = -1;
        cin >> id;
        cout << bfs(id, l, follower) << endl;
    }
}