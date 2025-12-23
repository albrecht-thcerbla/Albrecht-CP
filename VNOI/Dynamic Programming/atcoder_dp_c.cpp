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
  vector<vector<int>> a(n, vector<int>(3, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> a[i][j];
    }
  }
  vector<vector<int>> dp(n, vector<int>(3, 0));
  dp[0][0] = a[0][0];
  dp[0][1] = a[0][1];
  dp[0][2] = a[0][2];
  for (int i = 1; i < n; i++) {
    dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + a[i][0];
    dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + a[i][1];
    dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + a[i][2];
  }
  cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]}) << '\n';
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}

