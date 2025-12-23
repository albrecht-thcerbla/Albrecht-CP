#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
const int64_t inf = 1e18;

int n, m, dp[1001][1001];

int calc(int n, int m) {
  if (n == m) return 0;
  if (dp[n][m] != -1) return dp[n][m];
  int res = 1e9;
  for (int i = 1; i <= m - 1; i++) res = min(res, calc(n, i) + calc(n, m - i) + 1);
  for (int i = 1; i <= n - 1; i++) res = min(res, calc(i, m) + calc(n - i, m) + 1);
  return dp[n][m] = res;
}
int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cin.exceptions(cin.failbit);
  memset(dp, -1, sizeof dp);
  cin >> n >> m;
  cout << calc(n, m) << '\n';
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}

