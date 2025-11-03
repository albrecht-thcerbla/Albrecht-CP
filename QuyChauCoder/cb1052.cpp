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
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  int n, m; cin >> n >> m;
  vector<vector<int>> c(n + 1, vector<int>(m + 2, 0));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> c[i][j];
    }
  }
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, inf));
  vector<vector<int>> trace(n + 1, vector<int>(m + 1, 0));
  dp[0][0] = 0;
  for (int j = 1; j <= m; j++) {
    for (int i = 0; i <= n; i++) {
      for (int k = 0; k <= i; k++) {
        if (dp[i - k][j - 1] + c[k][j] < dp[i][j]) {
          dp[i][j] = dp[i - k][j - 1] + c[k][j];
          trace[i][j] = k;
        } else if (dp[i - k][j - 1] + c[k][j] == dp[i][j]) {
          if (k < trace[i][j]) trace[i][j] = k;
        }
      }
    }
  }
  cout << dp[n][m] << '\n';
  vector<int> tmp(m + 1, 0);
  int rem = n;
  for (int i = m; i >= 1; i--) {
    tmp[i] = trace[rem][i];
    rem -= tmp[i];
  }
  for (int i = 1; i <= m; i++) cout << tmp[i] << '\n';
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}