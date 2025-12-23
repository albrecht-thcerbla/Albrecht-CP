#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

const int mod = 998244353;
const int maxn = 1e5 + 7;
const int64_t inf = 1e18;

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cin.exceptions(cin.failbit);
  int tt; cin >> tt;
  while (tt--) {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin() + 1, a.end());
    vector<int> dp(n + 1, 0), ways(n + 1, 0);
    ways[0] = ways[1] = 1;
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++) {
      dp[i] = dp[i - 1];
      ways[i] = ways[i - 1];
      if (a[i] - a[i - 1] <= 1) {
        int res = dp[i - 2] + 1;
        if (res > dp[i]) {
          dp[i] = res;
          ways[i] = ways[i - 2];
        } else if (res == dp[i]) (ways[i] += ways[i - 2]) %= mod;
      }
      ways[i] %= mod;
    }
    cout << ways[n] % mod << '\n';
  }
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}

