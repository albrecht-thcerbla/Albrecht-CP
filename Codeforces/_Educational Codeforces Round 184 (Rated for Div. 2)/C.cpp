#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define int int64_t

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
    vector<int64_t> pref(n + 1, 0);
    int64_t sum = 0;
    for (int i = 0; i < n; i++) {
      int x; cin >> x;
      sum += x;
      pref[i + 1] = pref[i] + x;
    }
    int64_t ans = sum, res = -1e18;
    for (int i = 1; i <= n; i++) {
      int64_t tmp = pref[i - 1] + i - (int64_t)(i * i);
      res = max(res, tmp);
      int64_t tmp2 = (int64_t)(i * i) + i - pref[i] + res;
      ans = max(ans, sum + tmp2);
    }
    cout << ans << '\n';
  }
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}