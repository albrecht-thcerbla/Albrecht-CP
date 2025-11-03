#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int maxn = 303;

int a[maxn], dp[2][maxn][maxn];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  int tt; cin >> tt;
  while (tt--) {
    int n; cin >> n;
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= n; j++) {
        dp[0][i][j] = dp[1][i][j] = 0;
      }
    }  
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      int c = (i & 1);
      for (int j = 0; j <= n; j++) {
        for (int k = 0; k <= n; k++) {
          dp[c][j][k] = dp[c ^ 1][j][k];
        }
      }
      (dp[c][a[i]][0] += 1) %= mod;
      for (int j = 0; j <= n; j++) {
        for (int k = 0; k <= j; k++) {
          if (a[i] >= j) (dp[c][a[i]][k] += dp[c ^ 1][j][k]) %= mod;
          else if (a[i] >= k) (dp[c][j][a[i]] += dp[c ^ 1][j][k]) %= mod;
        }
      }
    }
    int ans = 1;
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j < i; j++) {
        (ans += dp[n & 1][i][j]) %= mod;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}