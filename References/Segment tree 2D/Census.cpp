/// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2272
#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;

struct SegmentTree {
  int n;
  vector<vector<int>> t1, t2;
  explicit SegmentTree(int n) : n(n) {
    t1.assign(n << 1, vector<int>(n << 1, INT_MAX));
    t2.assign(n << 1, vector<int>(n << 1, INT_MIN));
  }
  void update(int x, int y, int val) {
    x += n; y += n;
    t1[x][y] = t2[x][y] = val;
    for (int Y = y >> 1; Y; Y >>= 1) {
      t1[x][Y] = min(t1[x][Y << 1], t1[x][Y << 1 | 1]);
      t2[x][Y] = max(t2[x][Y << 1], t2[x][Y << 1 | 1]);
    }
    for (int X = x >> 1; X; X >>= 1) {
      for (int Y = y; Y; Y >>= 1) {
        t1[X][Y] = min(t1[X << 1][Y], t1[X << 1 | 1][Y]);
        t2[X][Y] = max(t2[X << 1][Y], t2[X << 1 | 1][Y]);
      }
    }
  }
  pair<int, int> get_y(int X, int y1, int y2) {
    int mn = INT_MAX, mx = INT_MIN;
    for (int Y1 = y1 + n, Y2 = y2 + n; Y1 < Y2; Y1 >>= 1, Y2 >>= 1) {
      if (Y1 & 1) {
        mn = min(mn, t1[X][Y1]);
        mx = max(mx, t2[X][Y1]);
        ++Y1;
      }
      if (Y2 & 1) {
        --Y2;
        mn = min(mn, t1[X][Y2]);
        mx = max(mx, t2[X][Y2]);
      }
    }
    return {mn, mx};
  }
  pair<int, int> get(int x1, int x2, int y1, int y2) {
    int mn = INT_MAX, mx = INT_MIN;
    for (int X1 = x1 + n, X2 = x2 + n; X1 < X2; X1 >>= 1, X2 >>= 1) {
      if (X1 & 1) {
        auto p = get_y(X1++, y1, y2);
        mn = min(mn, p.first);
        mx = max(mx, p.second);
      }
      if (X2 & 1) {
        auto p = get_y(--X2, y1, y2);
        mn = min(mn, p.first);
        mx = max(mx, p.second);
      }
    }
    return {mn, mx};
  }
};
int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  int n; cin >> n;
  vector<vector<int>> a(n, vector<int>(n));
  SegmentTree t(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
      t.update(i, j, a[i][j]);
    }
  }
  int q; cin >> q;
  while (q--) {
    char c; cin >> c;
    if (c == 'q') {
      int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
      auto ans = t.get(x1 - 1, x2, y1 - 1, y2);
      cout << ans.second << " " << ans.first << '\n';
    } else {
      int x, y, val; cin >> x >> y >> val;
      t.update(x - 1, y - 1, val);
    }
  }
  return 0;
}