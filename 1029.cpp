#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m, p1 = 0, p2 = 0;
  cin >> n;
  vector<long>v1(n);
  for (int i = 0; i < n; ++i) {
    cin >> v1[i];
  }
  cin >> m;
  vector<long>v2(m);
  for (int i = 0; i < m; ++i) {
    cin >> v2[i];
  }
  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end());
  for (int i = 0; i < (n + m - 1) / 2; ++i) {
    if (p1 == n) {
      ++p2;
    }
    else if (p2 == m) {
      ++p1;
    }
    else {
      if (v1[p1] < v2[p2]) {
        ++p1;
      }
      else {
        ++p2;
      }
    }
  }
  if (p1 == n)cout << v2[p2] << endl;
  else if (p2 == m)cout << v1[p1] << endl;
  else {
    if (v1[p1] < v2[p2])cout << v1[p1] << endl;
    else cout << v2[p2] << endl;
  }
}