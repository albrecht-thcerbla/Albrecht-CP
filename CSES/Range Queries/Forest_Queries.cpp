/**
ref: https://blog.garybricks.com/2d-prefix-array-and-2d-segment-tree-overview
**/

#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;

struct SegmentTree {
  int n;
  vector<vector<int>> t;
  SegmentTree(int n) : n(n) {
    t.assign(n << 2, vector<int>(n << 2, 0));
  }
  void update_y(int X, int lx, int rx, int x, int Y, int ly, int ry, int y, int val) {
    if (ly == ry) {
      if (lx == rx) t[X][Y] = val;
      else t[X][Y] = t[X << 1][Y] + t[X << 1 | 1][Y];
      return;
    } 
    int my = (ly + ry) >> 1;
    if (y <= my) update_y(X, lx, rx, x, Y << 1, ly, my, y, val);
    else update_y(X, lx, rx, x, Y << 1 | 1, my + 1, ry, y, val);
    t[X][Y] = t[X][Y << 1] + t[X][Y << 1 | 1];
  } 
  void update_x(int X, int lx, int rx, int x, int y, int val) {
    if (lx != rx) {
      int mx = (lx + rx) >> 1;
      if (x <= mx) update_x(X << 1, lx, mx, x, y, val);
      else update_x(X << 1 | 1, mx + 1, rx, x, y, val);
    }
    update_y(X, lx, rx, x, 1, 0, n - 1, y, val);
  }
  int64_t get_y(int X, int Y, int ly, int ry, int y1, int y2) {
    if (y1 > ry || y2 < ly) return 0;
    if (y1 <= ly && y2 >= ry) return t[X][Y];
    int my = (ly + ry) >> 1;
    return get_y(X, Y << 1, ly, my, y1, y2) + get_y(X, Y << 1 | 1, my + 1, ry, y1, y2);
  }
  int64_t get_x(int X, int lx, int rx, int x1, int x2, int y1, int y2) {
    if (x1 > rx || x2 < lx) return 0;
    if (x1 <= lx && x2 >= rx) return get_y(X, 1, 0, n - 1, y1, y2);
    int mx = (lx + rx) >> 1;
    return get_x(X << 1, lx, mx, x1, x2, y1, y2) + get_x(X << 1 | 1, mx + 1, rx, x1, x2, y1, y2);
  }
};
int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  // freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  // freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  int n, q; cin >> n >> q;
  SegmentTree t(n);
  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    for (int j = 0; j < n; j++) {
      if (a[i][j] == '*') t.update_x(1, 0, n - 1, i, j, 1);
    }
  }
  while (q--) {
    int y1, x1, y2, x2; cin >> y1 >> x1 >> y2 >> x2;
    x1--; x2--; y1--; y2--;
    cout << t.get_x(1, 0, n - 1, y1, y2, x1, x2) << '\n';
  }
  return 0;
}