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
  int n, m; cin >> m >> n;
  vector<vector<int>> a(m + 5, vector<int>(n + 5, 0));
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }
  vector<vector<int>> dp(m + 5, vector<int>(n + 5, -1e9));
  for (int i = 1; i <= m; i++) dp[i][1] = a[i][1];
  for (int j = 2; j <= n; j++) {
    for (int i = 1; i <= m; i++) {
      dp[i][j] = a[i][j] + max({dp[i][j - 1], dp[i - 1][j - 1], dp[i + 1][j - 1]});
    }
  }
  int ans = -1e9;
  for (int i = 1; i <= m; i++) ans = max(ans, dp[i][n]);
  cout << ans << '\n';
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}

