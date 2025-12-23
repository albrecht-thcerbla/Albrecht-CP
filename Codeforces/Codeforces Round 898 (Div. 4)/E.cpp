#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
const int64_t inf = 1e18;

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cin.exceptions(cin.failbit);
  int tt; cin >> tt;
  while (tt--) {
    int n, x; cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int64_t l = 0, r = 1e18;
    while (r - l > 1) {
      int64_t m = (l + r) >> 1;
      int64_t res = 0;
      for (int i = 0; i < n; i++) {
        if (m > a[i]) {
          res += (m - a[i]);
          if (res > x) break;
        }
      }
      if (res <= x) l = m;
      else r = m;
    }
    cout << l << '\n';
  }
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}

