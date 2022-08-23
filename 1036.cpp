#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static struct Student {
	string name, id;
	int grade;
};

static bool cmp(const Student& s1, const Student& s2) {
	return s1.grade < s2.grade;
}

//int main() {
//	char gender;
//	string name, id;
//	int grade, n; cin >> n;
//	vector<Student>male, female;
//	for (int i = 0; i < n; ++i) {
//		cin >> name >> gender >> id >> grade;
//		if (gender == 'M') {
//			male.push_back({ name, id, grade });
//		}
//		else {
//			female.push_back({ name, id, grade });
//		}
//	}
//	sort(male.begin(), male.end(), cmp);
//	sort(female.begin(), female.end(), cmp);
//	if (female.empty())cout << "Absent" << endl;
//	else cout << female.back().name << ' ' << female.back().id << endl;
//	if (male.empty())cout << "Absent" << endl;
//	else cout << male.front().name << ' ' << male.front().id << endl;
//	if (male.empty() || female.empty())cout << "NA" << endl;
//	else cout << female.back().grade - male.front().grade << endl;
//}