#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tt; cin >> tt;
  while (tt--) {
    int64_t x, y; cin >> x >> y;
    if (y > x) {
      cout << 2 << '\n';
      continue;
    }
    bool ok = false;
    if (y > 1 && y < x) {
      int64_t a1 = 1, a3 = x - a1;
      if (a3 > y) ok = true;
    }
    if (ok) {
      cout << 3 << '\n';
      continue;
    }
    cout << -1 << '\n';
  }
  return 0;
}