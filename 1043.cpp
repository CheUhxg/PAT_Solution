#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct BST {
	int v;
	BST* left = nullptr, * right = nullptr;
	BST(int v, BST* left, BST* right) : v(v), left(left), right(right) {}
};
int n;
bool isBST = true;

BST* buildBST(const int begin, const int end,
							const bool isMirror, const vector<int>& tree) {
	if (!isBST || begin > end)return nullptr;
	if (begin == end)return new BST(tree[begin], nullptr, nullptr);
	int left = begin + 1, right = end;
	for (int i = left; i <= end; ++i) {
		if (isMirror && tree[i] < tree[begin] || 
				!isMirror && tree[i] >= tree[begin]) {
			right = i;
			break;
		}
	}
	for (int i = right + 1; i <= end; ++i) {
		if (isMirror && tree[i] >= tree[begin] ||
				!isMirror && tree[i] < tree[begin]) {
			isBST = false;
			return nullptr;
		}
	}
	if (isBST) {
		BST* root = new BST(tree[begin], nullptr, nullptr);
		root->left = buildBST(left, right - 1, isMirror, tree);
		root->right = buildBST(right, end, isMirror, tree);
		return root;
	}
}

void printPostOrder(const BST* root, BST* node) {
	if (node->left)printPostOrder(root, node->left);
	if (node->right)printPostOrder(root, node->right);
	cout << node->v;
	if (node != root)cout << ' ';
}

int main() {
	cin >> n;
	vector<int> tree(n);
	for (int i = 0; i < n; ++i) {
		cin >> tree[i];
	}
	BST* root = buildBST(0, tree.size() - 1, false, tree);
	if (!isBST) {
		isBST = true;
		root = buildBST(0, tree.size() - 1, true, tree);
	}
	if (!isBST)cout << "NO" << endl;
	else {
		cout << "YES" << endl;
		printPostOrder(root, root);
		cout << endl;
	}
}