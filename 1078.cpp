#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m, n, t = -1; cin >> m >> n;
    vector<bool>isPrime(m, true);
    for(int i = 1; i <= m; ++i) {
        for(int j = i; j >= 2; --j) {
            if(i * j >= m && i * j < 2 * m) {
                isPrime[i * j - m] = false;
            }
        }
    }
    while(!isPrime[++t]);
    t += m;
    vector<bool>visited(t, false);
    while(n--) {
        cin >> m;
        int i;
        for(i = 0; i < t; ++i) {
            if(!visited[(m + i * i) % t]) {
                break;
            }
        }
        if(!visited[(m + i * i) % t]) {
            visited[(m + i * i) % t] = true;
            cout << (m + i * i) % t;
        }
        else cout << '-';
        if(n > 0)cout << ' ';
    }
    cout << endl;
}