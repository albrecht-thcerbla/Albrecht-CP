#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
const int64_t inf = 1e18;

struct Node {
  int64_t val;
  int cnt;
};

int n, q, a[maxn];
Node t[maxn << 1];

Node calc(Node a, Node b) {
  if (a.val < b.val) return a;
  else if (b.val < a.val) return b;
  return {a.val, a.cnt + b.cnt};
}
void build() {
  for (int i = 0; i < n; i++) t[n + i] = {a[i], 1};
  for (int i = n - 1; i > 0; i--) t[i] = calc(t[i << 1], t[i << 1 | 1]);
}
Node get(int l, int r) {
  Node resl = {inf, 1};
  Node resr = {inf, 1};
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1) resl = calc(resl, t[l++]);
    if (r & 1) resr = calc(resr, t[--r]);
  }
  return calc(resl, resr);
}
void update(int p, int64_t val) {
  for (t[p += n] = {val, 1}; p > 1; p >>= 1) t[p >> 1] = calc(t[p], t[p ^ 1]);
}
int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> q;
  for (int i = 0; i < n; i++) cin >> a[i];
  build();
  while (q--) {
    int ty; cin >> ty;
    if (ty == 1) {
      int pos; cin >> pos;
      int64_t val; cin >> val;
      update(pos, val);
    } else {
      int l, r; cin >> l >> r;
      Node res = get(l, r);
      cout << res.val << " " << res.cnt << '\n';
    }
  }
  return 0;
}