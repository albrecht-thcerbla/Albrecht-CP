#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
const int64_t inf = 1e18;

// Coin 3
/**
 * Cho n dong xu va can tao ra tong bang x.
 * Gia su so xu la {2, 3, 5} va tong mong muon la 9
 * Co 3 cach: (2 + 2 + 5), (3 + 3 + 3), (2 + 2 + 2 + 3).
 **/

int dp[101][1000001];

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cin.exceptions(cin.failbit);
  // freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  // freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  int n, s; cin >> n >> s;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 0; i <= n; i++) dp[i][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= s; j++) {
      if (j >= a[i]) dp[i][j] = dp[i][j - a[i]] + dp[i - 1][j];
      else dp[i][j] = dp[i - 1][j];
      dp[i][j] %= mod;
    }
  }  
  cout << dp[n][s] << '\n';
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}