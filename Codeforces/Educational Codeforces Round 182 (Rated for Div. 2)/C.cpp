#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 998244353;
const int maxn = 1e5 + 7;

int64_t dp[101][2];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  int tt; cin >> tt;
  while (tt--) {
    int n; cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 0; i <= n; i++) dp[i][0] = dp[i][1] = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    dp[1][0] = dp[1][1] = 1;
    for (int i = 2; i <= n; i++) {
      for (int p = 0; p <= 1; p++) {
        for (int c = 0; c <= 1; c++) {
          int ap = p ? b[i - 1] : a[i - 1];
          int bp = p ? a[i - 1] : b[i - 1];
          int ac = c ? b[i] : a[i];
          int bc = c ? a[i] : b[i];
          if (ap <= ac && bp <= bc) dp[i][c] = (dp[i][c] + dp[i - 1][p]) % mod;
        }
      }
    }
    int64_t ans = (dp[n][0] + dp[n][1]) % mod;
    cout << ans << '\n';
  }
  return 0;
}