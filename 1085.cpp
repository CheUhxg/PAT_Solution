#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//int main() {
//    long long p;
//    int n; cin >> n >> p;
//    vector<long long> num(n);
//    for(long long& i : num) {
//        cin >> i;
//    }
//    sort(num.begin(), num.end());
//    int low = 0, high = 0, max_len = 0;
//    while(high < num.size()) {
//        if(num[high] <= num[low] * p) {
//            ++high;
//        } else {
//            if(high - low > max_len) {
//                max_len = high - low;
//            }
//            ++low;
//        }
//    }
//    if(high - low > max_len) {
//        max_len = high - low;
//    }
//    cout << max_len << endl;
//}
