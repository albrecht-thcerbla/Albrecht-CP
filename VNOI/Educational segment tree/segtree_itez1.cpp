// https://oj.vnoi.info/contest/segtree
#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;

/**
 * First query "1 x y" : replace x with y.
 * Second query "2 l r": find max from l to r. 
 **/

int n, q;
vector<int> a, t;

void build() {
  for (int i = 0; i < n; i++) t[i + n] = a[i];
  for (int i = n - 1; i > 0; i--) t[i] = max(t[i << 1], t[i << 1 | 1]);
}
void update(int p, int val) {
  for (t[p += n] = val; p > 1; p >>= 1) t[p >> 1] = max(t[p], t[p ^ 1]);
}
int get(int l, int r) {
  int res = -1e9;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1) res = max(res, t[l++]);
    if (r & 1) res = max(res, t[--r]);
  }
  return res;
}
int32_t main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  a.resize(n);
  t.resize(n << 1);
  for (int i = 0; i < n; i++) cin >> a[i];
  build();
  cin >> q;
  while (q--) {
    int ty, x, y; cin >> ty >> x >> y;
    if (ty == 1) update(x - 1, y);
    else cout << get(x - 1, y) << '\n';
  }
  return 0;
}