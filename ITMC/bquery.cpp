#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
const int64_t inf = 1e18;

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  int n, m, q; cin >> n >> m >> q;
  vector<int64_t> r(n + 1, 0), c(m + 1, 0);
  while (q--) {
    int ty; cin >> ty;
    if (ty == 1) {
      int row; cin >> row;
      int64_t val; cin >> val;
      r[row] += val;
    } else if (ty == 2) {
      int col; cin >> col;
      int64_t val; cin >> val;
      c[col] += val;
    } else {
      int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
      int64_t maxr = -1e18, maxc = -1e18;
      for (int i = x1; i <= x2; i++) maxr = max(maxr, r[i]);
      for (int i = y1; i <= y2; i++) maxc = max(maxc, c[i]);
      cout << maxr + maxc << '\n';
    }
  }
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}