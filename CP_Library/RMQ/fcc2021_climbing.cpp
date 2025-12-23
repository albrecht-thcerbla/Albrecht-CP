#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define int int64_t

const int mod = 1e9 + 7;
const int maxn = 1e6 + 5;
const int64_t inf = 1e18;

int mn[21][maxn], mx[21][maxn];

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cin.exceptions(cin.failbit);
  int n, m, p; cin >> n >> m >> p;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    mn[0][i] = mx[0][i] = x;
  }
  for (int l = 1; (1 << l) <= n; l++) {
    for (int i = 1; i + (1 << l) - 1 <= n; i++) {
      mn[l][i] = min(mn[l - 1][i], mn[l - 1][i + (1 << (l - 1))]);
      mx[l][i] = max(mx[l - 1][i], mx[l - 1][i + (1 << (l - 1))]);
    }
  }
  bool ok = false;
  for (int i = 1; i + m - 1 <= n; i++) {
    int k = log2(m);
    int minn = min(mn[k][i], mn[k][(i + m - 1) - (1 << k) + 1]);
    int maxx = max(mx[k][i], mx[k][(i + m - 1) - (1 << k) + 1]);
    if (maxx - minn <= p) cout << i << '\n', ok = true;
  }
  if (!ok) cout << "NONE" << '\n';
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}

