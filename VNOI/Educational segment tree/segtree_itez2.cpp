#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;

/**
 *  1 x y: replace x with y.
 *  2 l r: sum from l to r.
 **/

int n, q;
vector<int> a;
vector<int64_t> t;

void build() {
  for (int i = 0; i < n; i++) t[i + n] = a[i];
  for (int i = n - 1; i > 0; i--) t[i] = t[i << 1] + t[i << 1 | 1];
}
void update(int p, int val) {
  for (t[p += n] = val; p > 1; p >>= 1) t[p >> 1] = t[p] + t[p ^ 1];
}
int64_t get(int l, int r) {
  int64_t res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1) res += t[l++];
    if (r & 1) res += t[--r];
  }
  return res;
}
int32_t main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> q;
  a.assign(n, 0); t.resize(n << 1);
  build();  
  while (q--) {
    int ty, x, y; cin >> ty >> x >> y;
    if (ty == 1) update(x - 1, y);
    else cout << get(x - 1, y) << '\n';
  }
  return 0;
}