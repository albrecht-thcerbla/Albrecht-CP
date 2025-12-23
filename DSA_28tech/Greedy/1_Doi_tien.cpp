#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  int cnt = 0, idx = 0;
  int a[] = {1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
  while (n) {
    cnt += (n / a[idx]);
    n %= a[idx];
    ++idx;
  }
  cout << cnt << '\n';
  return 0;
}