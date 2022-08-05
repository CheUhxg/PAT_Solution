#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <set>

using namespace std;

struct Team {
	int min_id = 0x3fffffff, sum_score = 0;
	set<int> students;
};
vector<Team> teams;

void Combine(Team& t) {
	vector<int> index;
	for (int i = 0; i < teams.size(); ++i) {
		if (teams[i].sum_score < 0)continue;
		for (const int& stu : t.students) {
			if (teams[i].students.count(stu) > 0) {
				index.push_back(i);
				break;
			}
		}
	}
	for (int i = 0; i < index.size(); ++i) {
		t.students.insert(teams[index[i]].students.begin(), teams[index[i]].students.end());
		t.min_id = min(t.min_id, teams[index[i]].min_id);
		t.sum_score += teams[index[i]].sum_score;
		teams[index[i]].sum_score = -1;
	}
	teams.push_back(t);
}

int getSize() {
	int i;
	for (i = 0; i < teams.size(); ++i) {
		if (teams[i].sum_score < 0)
			break;
	}
	return i;
}

bool cmp(const Team& t1, const Team& t2) {
	if (t1.sum_score == t2.sum_score) {
		if (t1.students.size() == t2.students.size())
			return t1.min_id < t2.min_id;
		return t1.students.size() < t2.students.size();
	}
	return  t1.sum_score > t2.sum_score;
}

int main() {
	int n, k, id; cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> id >> k;
		Team ttmp;
		ttmp.min_id = id;
		ttmp.students.insert(id);
		for (int i = 0; i < k; ++i) {
			cin >> id;
			ttmp.min_id = min(ttmp.min_id, id);
			ttmp.students.insert(id);
		}
		cin >> ttmp.sum_score;
		Combine(ttmp);
	}
	sort(teams.begin(), teams.end(), cmp);
	teams.resize(getSize());
	cout << teams.size() << endl;
	for (const Team& t : teams) {
		printf("%04d %d %d\n", t.min_id, t.students.size(), t.sum_score);
	}
}