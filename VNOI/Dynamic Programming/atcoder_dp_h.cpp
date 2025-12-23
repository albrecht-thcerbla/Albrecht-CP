#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
const int64_t inf = 1e18;

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cin.exceptions(cin.failbit);
  int h, w; cin >> h >> w;
  vector<string> a(h);
  for (int i = 0; i < h; i++) cin >> a[i];
  vector<int64_t> dp(w, 0);
  dp[0] = (a[0][0] == '.' ? 1 : 0);
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (a[i][j] == '#') dp[j] = 0;
      else if (j) (dp[j] += dp[j - 1]) %= mod;
    }
  }
  cout << dp[w - 1] << '\n';
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}

