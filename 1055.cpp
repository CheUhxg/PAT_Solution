#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

static struct Person {
	int age, worth;
	string name;
};

static bool cmp(const Person& p1, const Person& p2) {
	if (p1.worth == p2.worth) {
		if (p1.age == p2.age)return p1.name < p2.name;
		return p1.age < p2.age;
	}
	return p1.worth > p2.worth;
}

//int main() {
//	int n, k, m, low, high; cin >> n >> k;
//	vector<Person> people(n);
//	for (int i = 0; i < n; ++i) {
//		cin >> people[i].name >> people[i].age >> people[i].worth;
//	}
//	sort(people.begin(), people.end(), cmp);
//	for (int i = 1; i <= k; ++i) {
//		cin >> m >> low >> high;
//		cout << "Case #" << i << ':' << endl;
//		int cnt = 0;
//		for (const Person& p : people) {
//			if (p.age >= low && p.age <= high) {
//				cout << p.name << ' '
//					<< p.age << ' '
//					<< p.worth << endl;
//				if (++cnt == m)break;
//			}
//		}
//		if (cnt == 0) {
//			cout << "None" << endl;
//		}
//	}
//}