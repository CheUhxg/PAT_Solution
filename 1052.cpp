#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct Node {
	string addr, next;
	int value;
	bool isIn = false;
};

bool cmp(const Node& n1, const Node& n2) {
	if (n1.isIn != n2.isIn)return n1.isIn > n2.isIn;
	return n1.value < n2.value;
}

int main() {
	string start;
	int n, cnt = 0; cin >> n >> start;
	vector<Node> nodes(n + 1);
	unordered_map<string, int> index;
	nodes.back().addr = "-1";
	nodes.back().value = 100005;
	nodes.back().isIn = true;
	index["-1"] = n;
	for (int i = 0; i < n; ++i) {
		cin >> nodes[i].addr >> nodes[i].value >> nodes[i].next;
		index[nodes[i].addr] = i;
	}
	for (int i = index[start]; nodes[i].addr != "-1"; i = index[nodes[i].next]) {
		nodes[i].isIn = true;
		++cnt;
	}
	sort(nodes.begin(), nodes.end(), cmp);
	cout << cnt << ' ' << nodes[0].addr << endl;
	for (int i = 0; i < cnt; ++i) {
		cout << nodes[i].addr << ' '
			<< nodes[i].value << ' '
			<< nodes[i + 1].addr << endl;
	}
}