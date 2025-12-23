#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

const int mod = 1e9 + 7;
const int maxn = 2e5 + 7;
const int64_t inf = 1e18;

int p[32][maxn];

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cin.exceptions(cin.failbit);
  // freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  // freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  int n, q; cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> p[0][i];
  for (int i = 1; i <= 31; i++) {
    for (int u = 1; u <= n; u++) {
      p[i][u] = p[i - 1][p[i - 1][u]];
    }
  }
  while (q--) {
    int u, k; cin >> u >> k;
    for (int i = 0; i < 31; i++) if ((k >> i) & 1) u = p[i][u];
    cout << u << '\n';
  }
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}