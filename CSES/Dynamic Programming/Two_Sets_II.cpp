#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
const int64_t inf = 1e18;

vector<int> dp(505 * 505, 0);

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cin.exceptions(cin.failbit);
  int n; cin >> n;
  int sum = n * (n + 1) >> 1;
  if (!(sum & 1)) {
    sum >>= 1;
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
      vector<int> prev = dp;
      for (int j = 1; j <= sum; j++) {
        if (j >= i) dp[j] += prev[j - i];
        dp[j] %= mod;
      }
    }
    cout << ((int64_t)dp[sum] * ((mod + 1) / 2)) % mod << '\n';
  } else cout << 0 << '\n';
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}

