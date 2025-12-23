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
  int n, m; cin >> n >> m;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  vector<vector<int64_t>> dp(1001, vector<int64_t>(1001, 0));
  if (a[1]) dp[1][a[1]] = 1;
  else for (int j = 1; j <= m; j++) dp[1][j] = 1;
  for (int i = 2; i <= n; i++) {
    if (!a[i]) {
      for (int j = 1; j <= m; j++) (dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1]) %= mod;
    } else {
      (dp[i][a[i]] = dp[i - 1][a[i] - 1] + dp[i - 1][a[i]] + dp[i - 1][a[i] + 1]) %= mod;
    }
  }
  int ans = 0;
  for (int j = 1; j <= m; j++) ans += dp[n][j];
  cout << ans << '\n';
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}
