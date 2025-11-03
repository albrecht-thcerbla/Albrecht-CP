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
  // freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  // freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  int n, x; cin >> n >> x;
  vector<int> w(n + 1), v(n + 1);
  for (int i = 1; i <= n; i++) cin >> w[i];
  for (int i = 1; i <= n; i++) cin >> v[i];
  vector<int> dp(x + 1, 0);
  for (int i = 1; i <= n; i++) {
    vector<int> prev = dp;
    for (int j = 1; j <= x; j++) {
      if (j >= w[i]) dp[j] = max(dp[j], prev[j - w[i]] + v[i]);
    }
  }
  cout << dp[x] << '\n';
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}