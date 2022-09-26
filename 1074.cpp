#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Node {
	int add, data, next;
};

int main() {
	int start, n, k; cin >> start >> n >> k;
	unordered_map<int, Node> nodes;
	vector<Node>res;
	Node tmp;
	for (int i = 0; i < n; ++i) {
		cin >> tmp.add >> tmp.data >> tmp.next;
		nodes[tmp.add] = tmp;
	}
	while (start != -1) {
		res.push_back(nodes[start]);
		start = res.back().next;
	}
	int low = 0;
	while (low + k <= res.size()) {
		reverse(res.begin() + low, res.begin() + low + k);
		low += k;
	}
	for (int i = 0; i < res.size(); ++i) {
		printf("%05d %d ", res[i].add, res[i].data);
		if(i < res.size() - 1)
			printf("%05d\n", res[i + 1].add);
		else
			printf("-1\n");
	}
}