#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;

struct SegmentTree {
  int n;
  vector<vector<int>> t;
  explicit SegmentTree(int n) : n(n) {
    t.assign(n << 1, vector<int>(n << 1, 0));
  }
  void update(int x, int y, int val) {
    x += n; y += n;
    t[x][y] = val;
    for (int Y = y >> 1; Y; Y >>= 1) t[x][Y] = t[x][Y << 1] + t[x][Y << 1 | 1];
    for (int X = x >> 1; X; X >>= 1) {
      for (int Y = y; Y; Y >>= 1) t[X][Y] = t[X << 1][Y] + t[X << 1 | 1][Y];
    }
  }
  int get_y(int X, int y1, int y2) {
    int res = 0;
    for (int Y1 = y1 + n, Y2 = y2 + n; Y1 < Y2; Y1 >>= 1, Y2 >>= 1) {
      if (Y1 & 1) res += t[X][Y1++];
      if (Y2 & 1) res += t[X][--Y2];
    }
    return res;
  }
  int get(int x1, int x2, int y1, int y2) {
    int res = 0;
    for (int X1 = x1 + n, X2 = x2 + n; X1 < X2; X1 >>= 1, X2 >>= 1) {
      if (X1 & 1) res += get_y(X1++, y1, y2);
      if (X2 & 1) res += get_y(--X2, y1, y2);
    }
    return res;
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
      if (a[i][j] == '*') t.update(i, j, 1);
    }
  }
  while (q--) {
    int y1, x1, y2, x2; cin >> y1 >> x1 >> y2 >> x2;
    cout << t.get(y1 - 1, y2, x1 - 1, x2) << '\n';
  }
  return 0;
}