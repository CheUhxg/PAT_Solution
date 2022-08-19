#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdio>

using namespace std;

static struct Student {
	short grade;
	string id, name;
};

static bool cmp1(const Student& s1, const Student& s2) {
	return s1.id < s2.id;
}

static bool cmp2(const Student& s1, const Student& s2) {
	if(s1.name == s2.name)return s1.id < s2.id;
	return s1.name < s2.name;
}

static bool cmp3(const Student& s1, const Student& s2) {
	if (s1.grade == s2.grade)return s1.id < s2.id;
	return s1.grade < s2.grade;
}

//int main() {
//	int n, c; cin >> n >> c; cin.get();
//	vector<Student> student(n);
//	for (int i = 0; i < n; ++i) {
//		cin >> student[i].id >> student[i].name >> student[i].grade;
//		cin.get();
//	}
//	switch (c) {
//	case 1:
//		sort(student.begin(), student.end(), cmp1);
//		break;
//	case 2:
//		sort(student.begin(), student.end(), cmp2);
//		break;
//	case 3:
//		sort(student.begin(), student.end(), cmp3);
//		break;
//	}
//	for (const Student& s : student) {
//		cout << s.id << ' ' << s.name << ' ' << s.grade << endl;
//	}
//}