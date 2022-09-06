#include <iostream>
#include <vector>
#include <stack>

using namespace std;

//int main() {
//	int m, n, k; cin >> m >> n >> k;
//	vector<int>nums(n);
//	while (k--) {
//		stack<int> stk;
//		for (int i = 0; i < n; ++i) {
//			cin >> nums[i];
//		}
//		int index = 0;
//		for (int i = 1; i <= n && stk.size() < m;++i) {
//			stk.push(i);
//			while (!stk.empty() && stk.top() == nums[index]) {
//				stk.pop();
//				++index;
//			}
//		}
//		if (index == n)cout << "YES" << endl;
//		else cout << "NO" << endl;
//	}
//}