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
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  int tt; cin >> tt;
  while (tt--) {
    int h, d; cin >> h >> d;
    int maxd = d * (d + 1) >> 1;
    if (h >= maxd) {
      cout << h << '\n';
      continue;
    }
    int l = 0, r = d, ans = d;
    while (l <= r) {
      int m = (l + r) >> 1;
      int a = d / (m + 1);
      int r = d % (m + 1);
      int ca = r * ((a + 1) * (a + 2) / 2);
      int sa = (m + 1 - r) * (a * (a + 1) / 2);
      int c = ca + sa;
      if (c <= h + m - 1) {
        r = m - 1;
        ans = m;
      } else l = m + 1;
    }
    cout << (d + ans) << '\n';
  }
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}