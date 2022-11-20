#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

static struct Route {
    string dst;
    int cost;
};

static struct City {
    int happy = 0;
    vector<Route>routes;
};

static int min_cost = 0x3fffffff, max_happy = 0, cnt = 0;
static vector<string> res;
static unordered_map<string, int> name2index;

static bool isIn(const string& str, const vector<string>&path) {
    for(auto & p : path) {
        if(p == str)return true;
    }
    return false;
}

static void dfs(int index_now, int cost_totle, int happy_totle, vector<string>&path,
         const vector<City>& g, const int index_ROM) {
    if(index_now == index_ROM) {
        if(cost_totle < min_cost) {
            min_cost = cost_totle;
            max_happy = happy_totle;
            res = path;
            cnt = 1;
        } else if(cost_totle == min_cost) {
            ++cnt;
            if(happy_totle > max_happy) {
                max_happy = happy_totle;
                res = path;
            } else if(happy_totle == max_happy) {
                if(res.size() > path.size()) {
                    res = path;
                }
            }
        }
    }
    for(int i = 0; i < g[index_now].routes.size(); ++i) {
        if(!isIn(g[index_now].routes[i].dst, path)) {
            path.push_back(g[index_now].routes[i].dst);
            dfs(name2index[g[index_now].routes[i].dst], cost_totle + g[index_now].routes[i].cost,
                happy_totle + g[name2index[g[index_now].routes[i].dst]].happy,path, g, index_ROM);
            path.pop_back();
        }
    }
}

//int main() {
//    string start, src, dst;
//    int n, k, h; cin >> n >> k >> start; cin.get();
//    name2index[start] = 0;
//    vector<City> g(n);
//    for(int i = 1; i < n; ++i) {
//        cin >> src >> h;
//        name2index[src] = i;
//        g[i].happy = h;
//    }
//    for(int i = 0; i < k; ++i) {
//        cin >> src >> dst >> h;
//        g[name2index[src]].routes.push_back({dst, h});
//        g[name2index[dst]].routes.push_back({src, h});
//    }
//    vector<string>path;
//    dfs(0, 0, 0, path, g, name2index["ROM"]);
//    cout << cnt << ' ' << min_cost << ' ' << max_happy << ' ' << max_happy / res.size() << endl;
//    cout << start;
//    for(auto & str : res) {
//        cout << "->" << str;
//    }
//    cout << endl;
//}