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
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<int64_t> pref(n + 1, 0), prefmx(n + 1);;
    for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + a[i];
    for (int i = 1; i <= n; i++) prefmx[i] = max(prefmx[i - 1], pref[i]);
    vector<int64_t> m(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      int64_t res = prefmx[i] - pref[i];
      m[i] = max(m[i - 1], res);
    }
    int64_t ans = -1e18;
    for (int i = 0; i <= n; i++) ans = max(ans, pref[i]);
    for (int i = 1; i <= n; i++) ans = max(ans, pref[i] + m[i - 1]);
    cout << ans << '\n';
  }
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}
