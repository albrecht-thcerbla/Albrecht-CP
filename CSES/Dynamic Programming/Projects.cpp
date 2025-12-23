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
  int n; cin >> n;
  vector<array<int64_t, 3>> a(n + 1); // start - finish - profit
  vector<int64_t> dp(n + 1, 0);
  for (int i = 1; i <= n; i++) cin >> a[i][0] >> a[i][1] >> a[i][2];
  sort(a.begin() + 1, a.end(), [](array<int64_t, 3> a, array<int64_t, 3> b) {
    return a[1] < b[1];
  });
  auto bs = [&](int idx, int x) {
    int l = 0, r = idx;
    while (r - l > 1) {
      int m = (l + r) >> 1;
      if (a[m][1] <= x) l = m;
      else r = m;
    }
    return l;
  };
  for (int i = 1; i <= n; i++) {
    if (bs(i, a[i][0] - 1) == 0) dp[i] = max(dp[i - 1], a[i][2]);
    else dp[i] = max(dp[i - 1], dp[bs(i, a[i][0] - 1)] + a[i][2]);
  }
  cout << dp[n] << '\n';
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}
