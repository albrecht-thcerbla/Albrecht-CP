#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
const int64_t inf = 1e18;

int dp[1001][1001];

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cin.exceptions(cin.failbit);
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  string a, b; cin >> a >> b;
  int n = sz(a), m = sz(b);
  a = ' ' + a;
  b = ' ' + b;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
      else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }  
  cout << dp[n][m] << '\n';
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}