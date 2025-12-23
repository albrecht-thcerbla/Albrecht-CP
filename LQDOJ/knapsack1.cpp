#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
const int64_t inf = 1e18;

vector<int64_t> dp(100001, 0);

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cin.exceptions(cin.failbit);
  freopen("/home/albrecht/input.inp", "r", stdin);
  freopen("/home/albrecht/output.out", "w", stdout);
  int n, V; cin >> n >> V;
  vector<int> w(n + 1), v(n + 1);
  for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];
  for (int i = 1; i <= n; i++) {
    vector<int64_t> prev = dp;
    for (int j = 1; j <= V; j++) {
      if (j >= w[i]) dp[j] = max(prev[j], prev[j - w[i]] + v[i]);
      else dp[j] = prev[j];
    }
  }
  cout << dp[V] << '\n';
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}