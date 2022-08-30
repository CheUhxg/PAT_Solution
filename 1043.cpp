#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

static void buildBST(const int begin, const int end,	const bool isMirror,
							const vector<int>& pre, vector<int>& post) {
	if (begin > end)return;
	int left = begin + 1, right = end;
	if (isMirror) {
		while (left <= end && pre[left] >= pre[begin])++left;
		while (right >= left && pre[right] < pre[begin])--right;
	}
	else {
		while (left <= end && pre[left] < pre[begin])++left;
		while (right >= left && pre[right] >= pre[begin])--right;
	}
	buildBST(begin + 1, left - 1, isMirror, pre, post);
	buildBST(right + 1, end, isMirror, pre, post);
	post.push_back(pre[begin]);
}

//int main() {
//	int n; cin >> n;
//	vector<int> pre(n), post;
//	for (int i = 0; i < n; ++i) {
//		cin >> pre[i];
//	}
//	buildBST(0, pre.size() - 1, false, pre, post);
//	if (post.size() < n) {
//		post.clear();
//		buildBST(0, pre.size() - 1, true, pre, post);
//	}
//	if (post.size() < n)cout << "NO" << endl;
//	else {
//		cout << "YES" << endl;
//		cout << post[0];
//		for (int i = 1; i < n; ++i) {
//			cout << ' ' << post[i];
//		}
//		cout << endl;
//	}
//}