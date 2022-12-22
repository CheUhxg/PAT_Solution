#include <iostream>
#include <vector>
#include <queue>

using namespace std;

static int m, n, l, t;

static struct Point {
    int x, y, z;
};

static Point direct[6] = {
    {1, 0, 0},
    {0, 1, 0},
    {0, 0, 1},
    {-1, 0, 0},
    {0, -1, 0},
    {0, 0, -1},
};

static bool isRight(const Point& p,
             const vector<vector<vector<bool>>>& g,
             const vector<vector<vector<bool>>>& visited) {
    if(p.x >= 0 && p.x < m &&
        p.y >= 0 && p.y < n &&
        p.z >= 0 && p.z < l &&
        g[p.x][p.y][p.z] &&
        !visited[p.x][p.y][p.z]) return true;
    return false;
}

static int bfs(const Point& now,
         const vector<vector<vector<bool>>>& g,
         vector<vector<vector<bool>>>& visited) {
    int cnt = 1;
    queue<Point>q;
    q.push(now);
    visited[now.x][now.y][now.z] = true;
    while(!q.empty()) {
        int size = q.size();
        while(size-- > 0) {
            Point& p = q.front();
            for(const auto& d : direct) {
                Point tmp({p.x + d.x, p.y + d.y, p.z + d.z});
                if(isRight(tmp, g, visited)) {
                    ++cnt;
                    q.push(tmp);
                    visited[tmp.x][tmp.y][tmp.z] = true;
                }
            }
            q.pop();
        }
    }
    return cnt >= t?cnt:0;
}

//int main() {
//    cin >> m >> n >> l >> t;
//    vector<vector<vector<bool>>> g(m, vector<vector<bool>>(n, vector<bool>(l)));
//    vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(l, false)));
//    int cnt;
//    for(int z = 0; z < l; ++z) {
//        for(int x = 0; x < m; ++x) {
//            for(int y = 0; y < n; ++y) {
//                cin >> cnt;
//                g[x][y][z] = cnt;
//            }
//        }
//    }
//    cnt = 0;
//    for(int x = 0; x < m; ++x) {
//        for(int y = 0; y < n; ++y) {
//            for(int z = 0; z < l; ++z) {
//                if(!visited[x][y][z] && g[x][y][z])
//                    cnt += bfs({x, y, z}, g, visited);
//            }
//        }
//    }
//    cout << cnt << endl;
//}