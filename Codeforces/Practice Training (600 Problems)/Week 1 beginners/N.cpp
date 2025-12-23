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
  freopen("/home/albrecht/input.inp", "r", stdin);
  freopen("/home/albrecht/output.out", "w", stdout);
  int tt; cin >> tt;
  while (tt--) {
    int n, m, x, y; cin >> n >> m >> x >> y;
    vector<string> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int j = 0;
      while (j < m) {
        if (a[i][j] == '*') {
          ++j;
          continue;
        }
        if (j + 1 < m && a[i][j + 1] == '.') {
          if (y < 2 * x) ans += y, j += 2;
          else ans += x, ++j;
        } else ans += x, ++j;
      }
    }
    cout << ans << '\n';
  }
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}