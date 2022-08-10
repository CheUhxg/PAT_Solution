#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

static vector<vector<int>> tree;

static void MakeTree(const vector<int>& postorder, const vector<int>& inorder, const int layer) {
	if (postorder.size() == 0)return;
	int last_in = find(inorder.begin(), inorder.end(), postorder.back()) - inorder.begin();
	vector<int>post_left(postorder.begin(), postorder.begin() + last_in);
	vector<int>post_right(postorder.begin() + last_in, postorder.end() - 1);
	vector<int>in_left(inorder.begin(), inorder.begin() + last_in);
	vector<int>in_right(inorder.begin() + last_in + 1, inorder.end());
	if (tree.size() == layer) {
		tree.push_back({ inorder[last_in] });
	}
	else {
		tree[layer].push_back(inorder[last_in]);
	}
	MakeTree(post_left, in_left, layer + 1);
	MakeTree(post_right, in_right, layer + 1);
}

//int main() {
//	int n; cin >> n;
//	vector<int> postorder(n), inorder(n);
//	for (int i = 0; i < n; ++i) {
//		cin >> postorder[i];
//	}
//	for (int i = 0; i < n; ++i) {
//		cin >> inorder[i];
//	}
//	MakeTree(postorder, inorder, 0);
//	cout << tree[0][0];
//	for (int i = 1; i < tree.size(); ++i) {
//		for (int j = 0; j < tree[i].size(); ++j) {
//			cout << ' ' << tree[i][j];
//		}
//	}
//	cout << endl;
//}