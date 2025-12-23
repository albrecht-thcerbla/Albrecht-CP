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
  vector<int> t(n), r(n - 1);
  for (int i = 0; i < n; i++) cin >> t[i];
  for (int i = 0; i < n - 1; i++) cin >> r[i];
  vector<int> dp(n, 0);
  dp[0] = t[0];
  dp[1] = min(t[0] + t[1], r[0]);
  for (int i = 2; i < n; i++) dp[i] = min(dp[i - 1] + t[i], dp[i - 2] + r[i - 1]);
  cout << dp[n - 1] << '\n';
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}

