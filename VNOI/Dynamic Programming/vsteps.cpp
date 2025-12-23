#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

const int mod = 14062008;
const int maxn = 1e5 + 7;
const int64_t inf = 1e18;

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cin.exceptions(cin.failbit);
  int n, k; cin >> n >> k;
  vector<bool> a(n + 1, true);
  for (int i = 0; i < k; i++) {
    int x; cin >> x;
    a[x] = false;
  }
  vector<int> dp(n + 1, 0);
  dp[1] = 1;
  dp[2] = a[2];
  for (int i = 3; i <= n; i++) {
    if (!a[i]) dp[i] = 0;
    else (dp[i] = dp[i - 1] + dp[i - 2]) %= mod;
  }
  cout << dp[n] % mod << '\n';
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}

