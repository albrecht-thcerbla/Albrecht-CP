#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define int long long

const int mod = 100000;
const int maxn = 1e5 + 7;

int dp[202][202];

int count(char a, char b) {
  char o[3] = {'(', '[', '{'};
  char c[3] = {')', ']', '}'};
  int cnt = 0;
  for (int i = 0; i < 3; i++) {
    if ((a == '?' || a == o[i]) && (b == '?' || b == c[i])) ++cnt;
  }
  return cnt;
}
int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  string s; cin >> s;
  if (n & 1) return cout << 0, 0; 
  for (int len = 2; len <= n; len += 2) {
    for (int i = 0; i + len - 1 < n; i++) {
      int j = i + len - 1;
      int64_t ans = 0;
      for (int k = i + 1; k <= j; k++) {
        int m = count(s[i], s[k]);
        if (!m) continue;
        int l = 1, r = 1;
        if (i + 1 <= k - 1) l = dp[i + 1][k - 1];
        if (k + 1 <= j) r = dp[k + 1][j];
        ans += 1LL * m * l % mod * r % mod;
        if (ans >= (1LL << 62)) ans %= mod;
      }
      dp[i][j] = ans % mod;
    }
  }  
  cout << dp[0][n - 1] % mod << '\n';
  return 0;
}