#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Person {
	int id, vir, tal;
	char type;
};

bool cmp(const Person& p1, const Person& p2) {
	if (p1.type == p2.type) {
		if (p1.vir + p1.tal == p2.vir + p2.tal) {
			if(p1.vir == p2.vir) return p1.id < p2.id;
			return p1.vir > p2.vir;
		}
		return p1.vir + p1.tal > p2.vir + p2.tal;
	}
	return p1.type > p2.type;
}

int main() {
	int n, l, h; cin >> n >> l >> h;
	vector<Person> people(n);
	int cnt = n;
	for (int i = 0; i < n; ++i) {
		cin >> people[i].id >> people[i].vir >> people[i].tal;
		if (people[i].vir < l || people[i].tal < l) {
			people[i].type = '\0';
			--cnt;
		}
		else if (people[i].vir >= h && people[i].tal >= h) {
			people[i].type = 's';
		}
		else if (people[i].vir >= h && people[i].tal < h) {
			people[i].type = 'n';
		}
		else if (people[i].vir < h && people[i].tal < h &&
					people[i].vir >= people[i].tal) {
			people[i].type = 'f';
		}
		else {
			people[i].type = 'a';
		}
	}
	sort(people.begin(), people.end(), cmp);
	cout << cnt << endl;
	for (int i = 0; i < cnt; ++i) {
		printf("%08d %d %d", people[i].id, people[i].vir, people[i].tal);
		if (i != cnt - 1)cout << endl;
	}
}