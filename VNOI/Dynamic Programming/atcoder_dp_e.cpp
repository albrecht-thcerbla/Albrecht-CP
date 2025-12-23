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
  int n, W; cin >> n >> W;
  vector<int> w(n), v(n);
  int vmax = 0;
  for (int i = 0; i < n; i++) {
    cin >> w[i] >> v[i];
    vmax += v[i];
  }
  vector<vector<int64_t>> dp(n, vector<int64_t>(vmax + 1, -1));
  auto calc = [&](int idx, int k, auto self) -> int64_t {
    if (idx == n) return (k == 0 ? 0 : inf);
    if (dp[idx][k] != -1) return dp[idx][k];
    int64_t res = self(idx + 1, k, self);
    if (k >= v[idx]) res = min(res, self(idx + 1, k - v[idx], self) + w[idx]);
    return dp[idx][k] = res;
  };
  for (int i = vmax; ~i; i--) {
    int64_t need = calc(0, i, calc);
    if (need <= W) {
      cout << i << '\n';
      return 0;
    }
  }
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}

