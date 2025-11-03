#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
const int64_t inf = 1e9;

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cin.exceptions(cin.failbit);
  // freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  // freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  int n; cin >> n;
  vector<int> dp(n + 1, inf);
  dp[0] = 0;
  for (int s = 1; s <= n; s++) {
    int d = s;
    while (d) {
      int digit = d % 10;
      d /= 10;
      if (!digit) continue;
      if (s - digit >= 0) dp[s] = min(dp[s], dp[s - digit] + 1);
    }
  }
  cout << dp[n] << '\n';
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}