#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<cstdio>

using namespace std;

struct Player {
	bool vip;
	int arrive, serve = 0, play, leave;
};

struct Table {
	bool vip = false;
	int cnt = 0, serving = -1;
};

bool cmp_arrive(const Player& p1, const Player& p2) {
	return p1.arrive < p2.arrive;
}

bool cmp_serve(const Player& p1, const Player& p2) {
	return p1.serve < p2.serve;
}

int main() {
	char c;
	int n, k, m, hh, mm, ss, cur, serving; cin >> n;
	vector<Player> player(n);
	for (int i = 0; i < n; ++i) {
		cin >> hh >> c >> mm >> c >> ss >> player[i].play >> player[i].vip;
		player[i].arrive = hh * 3600 + mm * 60 + ss;
		player[i].play *= 60;
		if (player[i].play > 7200)player[i].play = 7200;
	}
	sort(player.begin(), player.end(), cmp_arrive);
	cin >> k >> m;
	vector<Table> table(k + 1);
	for (int i = 0; i < m; ++i) {
		cin >> cur;
		table[cur].vip = true;
	}
	cur = 0;
	queue<int> all, vips;
	for (int time = 28800; time < 75600; ++time) {
		for (int i = 1; i <= k; ++i) {
			serving = table[i].serving;
			if (serving != -1 && player[serving].leave == time) {
				table[i].serving = -1;
			}
		}

		while (cur < n && player[cur].arrive == time) {
			all.push(cur);
			if (player[cur].vip)vips.push(cur);
			++cur;
		}

		while (!vips.empty() && player[vips.front()].serve > 0)vips.pop();
		for (int i = 1; i <= k; ++i) {
			if (table[i].vip && table[i].serving == -1) {
				if (!vips.empty()) {
					table[i].serving = vips.front();
					++table[i].cnt;
					player[table[i].serving].serve = time;
					player[table[i].serving].leave = time + player[table[i].serving].play;
					while (!vips.empty() && player[vips.front()].serve > 0)vips.pop();
				}
			}
		}
		while (!all.empty() && player[all.front()].serve > 0)all.pop();
		for (int i = 1; i <= k; ++i) {
			if (table[i].serving == -1) {
				if (!all.empty()) {
					table[i].serving = all.front();
					++table[i].cnt;
					player[table[i].serving].serve = time;
					player[table[i].serving].leave = time + player[table[i].serving].play;
					while (!all.empty() && player[all.front()].serve > 0)all.pop();
				}
			}
		}
	}
	sort(player.begin(), player.end(), cmp_serve);
	for (const Player& p : player) {
		if (p.serve == 0)continue;
		hh = p.arrive / 3600;
		mm = p.arrive % 3600 / 60;
		ss = p.arrive % 60;
		printf("%02d:%02d:%02d ", hh, mm, ss);
		hh = p.serve / 3600;
		mm = p.serve % 3600 / 60;
		ss = p.serve % 60;
		printf("%02d:%02d:%02d ", hh, mm, ss);
		printf("%d\n", (p.serve - p.arrive + 30) / 60);
	}
	cout << table[1].cnt;
	for (int i = 2; i <= k; ++i) {
		printf(" %d", table[i].cnt);
	}
	cout << endl;
}