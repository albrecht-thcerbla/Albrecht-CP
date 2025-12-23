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
  int n, k; cin >> n >> k;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  vector<int> dp(n + 1, 1e9);
  dp[1] = 0;
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      if (i - j >= 1) dp[i] = min(dp[i], dp[i - j] + abs(a[i] - a[i - j]));
    }
  }
  cout << dp[n] << '\n';
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}

