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
    int r0, x, d, n; cin >> r0 >> x >> d >> n;
    string s; cin >> s;
    int l = r0, r = r0, ans = 0;
    for (int i = 0; i < sz(s); i++) {
      int ll, rr;
      if (s[i] == '1') {
        ll = l - d;
        rr = r + d;
        l = ll; r = rr;
        ++ans;
      } else {
        if (r < x) {
          ll -= d;
          rr += d;
          ++ans;
        } else if (l < x) {
          int rateL = l - d;
          int rateR = min(r, x - 1) + d;
          int unrateL = x;
          int unrateR = r;
          l = min(rateL, unrateL);
          r = max(rateR, unrateR);
          ++ans;
        }
      }
    }
    cout << ans << '\n';
  }
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}