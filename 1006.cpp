#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

struct p {
	string id, start, end;
};

//int main() {
//	p early, later;
//	string id, start, end;
//	int n; cin >> n; cin.get();
//	while (n--) {
//		cin >> id >> start >> end;
//		if (early.start.empty() || start < early.start) {
//			early.id = id;
//			early.start = start;
//		}
//		if (later.end.empty() || end > later.end) {
//			later.id = id;
//			later.end = end;
//		}
//	}
//	cout << early.id << ' ' << later.id << endl;
//}