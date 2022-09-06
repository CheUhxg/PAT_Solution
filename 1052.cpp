#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
	string addr;
	int value;
};

bool cmp(const Node& n1, const Node& n2) {
	return n1.value < n2.value;
}

int main() {
	int n, tmp; cin >> n >> tmp;
	vector<Node> nodes(n + 1);
	nodes.back().addr = "-1";
	nodes.back().value = 100005;
	for (int i = 0; i < n; ++i) {
		cin >> nodes[i].addr >> nodes[i].value >> tmp;
	}
	sort(nodes.begin(), nodes.end(), cmp);
	cout << n << ' ' << nodes[0].addr << endl;
	for (int i = 0; i < n; ++i) {
		cout << nodes[i].addr << ' '
			<< nodes[i].value << ' '
			<< nodes[i + 1].addr << endl;
	}
}