#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
#include <algorithm>

using namespace std;

struct Ganster {
	unordered_set<string> related;
	int time;
};

void dfs(unordered_set<string>& visited, const string& now, map<string, Ganster>& g) {
	visited.insert(now);
	for (const auto& other : g[now].related) {
		if (visited.count(other) == 0) {
			dfs(visited, other, g);
		}
	}
}

int main() {
	string name1, name2;
	int n, k, t; cin >> n >> k;
	map<string, Ganster> g;
	map<string, int> res;
	for (int i = 0; i < n; ++i) {
		cin >> name1 >> name2 >> t;
		g[name1].related.insert(name2);
		g[name1].time += t;

		g[name2].related.insert(name1);
		g[name2].time += t;
	}
	t = 0;
	unordered_set<string> visited;
	for (const auto& ganster : g) {
		if (visited.count(ganster.first) == 0) {
			unordered_set<string> vlist;
			dfs(vlist, ganster.first, g);
			if (vlist.size() >= 3) {
				int totle = 0;
				string head;
				for (const string& name : vlist) {
					visited.insert(name);
					totle += g[name].time;
					if (head.empty() || g[name].time > g[head].time) {
						head = name;
					}
				}
				if (totle - g[head].time > k) {
					++t;
					res[head] = vlist.size();
				}
			}
		}
	}
	cout << t << endl;
	if (t > 0) {
		for (const auto& p : res) {
			cout << p.first << ' ' << p.second << endl;
		}
	}
}