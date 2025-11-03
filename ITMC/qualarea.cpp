#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
const int64_t inf = 1e18;

struct Point { 
  int x, y;
};
int calc(Point& a, Point& b, Point& c) {
  return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}
int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cin.exceptions(cin.failbit);
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  int n; cin >> n;
  vector<Point> p(n);
  for (int i = 0; i < n; i++) cin >> p[i].x >> p[i].y;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int maxl = 0, maxr = 0;
      for (int k = 0; k < n; k++) {
        if (k == i || k == j) continue;
        int c = calc(p[i], p[j], p[k]);
        int a = abs(c);
        if (c > 0) {
          if (a > maxl) maxl = a;
        } else if (c < 0) {
          if (a > maxr) maxr = a;
        }
      }
      if (maxl > 0 && maxr > 0) ans = max(ans, maxl + maxr);
    }
  }
  cout << ans << '\n';
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}