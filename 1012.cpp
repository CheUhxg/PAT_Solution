#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

static struct Grades {
	int A, C, M, E;
};

static unordered_map<string, Grades>students;

//int main() {
//	int n, m;	cin >> n >> m; cin.get();
//	vector<int> A(n), C(n), M(n), E(n);
//	string id;
//	for (int i = 0; i < n; ++i) {
//		cin >> id >> C[i] >> M[i] >> E[i];
//		cin.get();
//		A[i] = C[i] + M[i] + E[i];
//		students[id] = { A[i], C[i], M[i], E[i] };
//	}
//	sort(A.begin(), A.end(), greater<int>());
//	sort(C.begin(), C.end(), greater<int>());
//	sort(M.begin(), M.end(), greater<int>());
//	sort(E.begin(), E.end(), greater<int>());
//
//	while (m--) {
//		getline(cin, id);
//		if (students.count(id) == 0) {
//			cout << "N/A" << endl;
//		}
//		else {
//			int best = n,res;
//			char dire = 'A';
//			Grades& tmp = students[id];
//			if (best > (res = find(A.begin(), A.end(), tmp.A) - A.begin()) + 1) {
//				best = res + 1;
//			} 
//			if (best > (res = find(C.begin(), C.end(), tmp.C) - C.begin()) + 1) {
//				best = res + 1;
//				dire = 'C';
//			}
//			if (best > (res = find(M.begin(), M.end(), tmp.M) - M.begin()) + 1) {
//				best = res + 1;
//				dire = 'M';
//			}
//			if (best > (res = find(E.begin(), E.end(), tmp.E) - E.begin()) + 1) {
//				best = res + 1;
//				dire = 'E';
//			}
//			cout << best << ' ' << dire << endl;
//		}
//	}
//}