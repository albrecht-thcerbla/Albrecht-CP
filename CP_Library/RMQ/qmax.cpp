#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

const int mod = 1e9 + 7;
const int maxn = 50005;
const int64_t inf = 1e18;

int a[maxn], f[21][maxn], pref[maxn];

int get(int l, int r) {
  int k = log2(r - l + 1);
  return max(f[k][l], f[k][r - (1 << k) + 1]);
}
int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cin.exceptions(cin.failbit);
  int n, m; cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v, k; cin >> u >> v >> k;
    pref[u] += k;
    pref[v + 1] -= k;
  }
  for (int i = 1; i <= n; i++) {
    pref[i] += pref[i - 1];
    f[0][i] = pref[i];
  }
  for (int l = 1; (1 << l) <= n; l++) {
    for (int i = 1; i + (1 << l) - 1 <= n; i++) {
      f[l][i] = max(f[l - 1][i], f[l - 1][i + (1 << l - 1)]);
    }
  }
  int q; cin >> q;
  while (q--) {
    int l, r; cin >> l >> r;
    cout << get(l, r) << '\n';
  }
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}

