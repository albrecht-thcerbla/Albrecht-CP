#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
const int64_t inf = 1e18;

int n, q, a[maxn], mi[21][maxn];
int get(int l, int r) {
  int k = log2(r - l + 1);
  return min(mi[k][l], mi[k][r - (1 << k) + 1]);
}
int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cin.exceptions(cin.failbit);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> a[i], mi[0][i] = a[i];
  for (int l = 1; (1 << l) <= n; l++) {
    for (int i = 1; i + (1 << l) - 1 <= n; i++) {
      mi[l][i] = min(mi[l - 1][i], mi[l - 1][i + (1 << l - 1)]);
    }
  }
  while (q--) {
    int l, r; cin >> l >> r;
    cout << get(l, r) << '\n';
  }
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}

