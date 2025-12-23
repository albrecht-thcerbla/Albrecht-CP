#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
const int64_t inf = 1e18;

int n, k, K, pop;
int dp[62][2][32];

int calc(int i, int carry, int used) {
  if (i == 60) return (carry ? 1 : 0);
  if (dp[i][carry][used] != -1) return dp[i][carry][used];
  int ni = (i < 30 ? ((n >> i) & 1) : 0);
  int res = 1e9;
  int sum0 = ni + carry;
  int yi0 = sum0 & 1;
  int c20 = sum0 >> 1;
  res = min(res, yi0 + calc(i + 1, c20, used));
  if (used < K) {
    int sum1 = ni + carry + 1;
    int yi1 = sum1 & 1;
    int c21 = sum1 >> 1;
    res = min(res, yi1 + calc(i + 1, c21, used + 1));
  }
  return dp[i][carry][used] = res;
}
int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cin.exceptions(cin.failbit);
  int tt; cin >> tt;
  while (tt--) {
    cin >> n >> k;
    pop = __builtin_popcount(n);
    K = min(k, 30);
    memset(dp, -1, sizeof dp);
    int mn = calc(0, 0, 0);
    int ans = k + pop - mn;
    cout << ans << '\n';
  }
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}

