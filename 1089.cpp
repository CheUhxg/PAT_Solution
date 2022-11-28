#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, no_inc = -1, tmp; cin >> n;
    vector<int>origin(n), now(n);
    for(int i = 0; i < n; ++i) {
        cin >> origin[i];
    }
    for(int i = 0; i < n; ++i) {
        cin >> now[i];
        if(no_inc == -1 && i > 0 && now[i] < now[i-1]) {
            no_inc = i;
        }
    }
    tmp = no_inc;
    while(no_inc < n) {
        if(now[no_inc] != origin[no_inc]) {
            break;
        }
        ++no_inc;
    }
    if(no_inc == n) {
        cout << "Insertion Sort" << endl;
        sort(origin.begin(), origin.begin() + tmp + 1);
    } else {
        cout << "Merge Sort" << endl;
        int len = 2, i;
        bool isMatch = true;
        while(isMatch) {
            isMatch = now != origin;
            for(i = 0; i+len < n; i += len) {
                sort(origin.begin()+i, origin.begin()+i+len);
            }
            sort(origin.begin() + i, origin.end());
            len *= 2;
        }
    }
    cout << origin[0];
    for(int i = 1; i < n; ++i) {
        cout << ' ' << origin[i];
    }
}