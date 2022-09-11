#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

static struct Mouse {
	int weight, round;
};

//int main() {
//	int Np, Ng, index; cin >> Np >> Ng;
//	vector<Mouse>mouses(Np);
//	for (int i = 0; i < Np; ++i) {
//		cin >> mouses[i].weight;
//	}
//	queue<int>order;
//	for (int i = 0; i < Np; ++i) {
//		cin >> index;
//		order.push(index);
//	}
//	int exist = Np;
//	while (order.size() > 1) {
//		int group = (exist + Ng - 1) / Ng;
//		for (int r = 0; r < group; ++r) {
//			int winner = order.front();
//			for (int i = 0; i < Ng && r * Ng + i < exist; ++i) {
//				int other = order.front();
//				if (mouses[winner].weight < mouses[other].weight)winner = other;
//				mouses[other].round = group + 1;
//				order.pop();
//			}
//			order.push(winner);
//		}
//		exist = group;
//	}
//	mouses[order.front()].round = 1;
//	cout << mouses[0].round;
//	for (int i = 1; i < Np; ++i) {
//		cout << ' ' << mouses[i].round;
//	}
//	cout << endl;
//}