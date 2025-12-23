#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, x; cin >> n >> x;
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    int c; cin >> c;
    if (c == x) ++cnt;
  }
  cout << cnt;
  return 0;
}