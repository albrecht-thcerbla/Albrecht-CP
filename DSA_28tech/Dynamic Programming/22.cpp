#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
const int64_t inf = 1e18;
/**
235
1. 2
2. 23 + 3
3. 235 + 35 + 5

=> dp[3] = dp[2] * 10 + 3 * a[3];
=> dp[i] = dp[i - 1] * 10 + i * a[i];

**/
int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cin.exceptions(cin.failbit);
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  string s; cin >> s;
  s = '0' + s;
  vector<int> dp(sz(s), 0);
  int64_t ans = 0;
  for (int i = 1; i <= sz(s) - 1; i++) ans += (dp[i] = dp[i - 1] * 10 + i * (s[i] ^ '0'));
  cout << ans << '\n';
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}