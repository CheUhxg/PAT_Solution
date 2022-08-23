#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
#include <algorithm>

using namespace std;

struct Ganster {
	unordered_set<string> related;
	string head;
	int time;
	bool visited = false;
};

string FindHead(const string& me, map<string, Ganster>& record) {
	if (!record[me].visited) {
		record[me].visited = true;
		string head(record[me].head);
		for (const string& other : record[me].related) {
			if (record[other].time > record[head].time) {
				head = other;
			}
		}
		if (head != record[me].head)record[me].head = FindHead(head, record);
	}
	return record[me].head;
}

int main() {
	string name1, name2;
	int n, k, t; cin >> n >> k;
	map<string, Ganster> record;
	map<string, int> res;
	for (int i = 0; i < n; ++i) {
		cin >> name1 >> name2 >> t;
		record[name1].related.insert(name2);
		record[name1].head = name1;
		record[name1].time += t;

		record[name2].related.insert(name1);
		record[name2].head = name2;
		record[name2].time += t;
	}
	for (auto& ganster : record) {
		ganster.second.head = FindHead(ganster.first, record);
		res[ganster.second.head] += 10000;
		if (ganster.second.head != ganster.first)
			res[ganster.second.head] += record[ganster.first].time;
	}
	t = 0;
	for (const auto& p : res) {
		if (p.second / 10000 >= 3 && p.second % 10000 > k) ++t;
	}
	cout << t << endl;
	if (t > 0) {
		for (const auto& p : res) {
			if (p.second / 10000 >= 3 && p.second % 10000 > k) {
				cout << p.first << ' ' << p.second / 10000 << endl;
			}
		}
	}
}