#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;

int n, q, h;
vector<int64_t> a, lazy, t;

void build() {
  for (int i = 0; i < n; i++) t[i + n] = a[i];
  for (int i = n - 1; i > 0; i--) t[i] = max(t[i << 1], t[i << 1 | 1]);
}

void apply(int p, int64_t val) {
  t[p] += val;
  if (p < n) lazy[p] += val;
}

void push_up(int p) {
  while (p > 1) {
    p >>= 1;
    t[p] = max(t[p << 1], t[p << 1 | 1]) + lazy[p];
  }
}

void push_down(int p) {
  for (int s = h; s > 0; s--) {
    int i = p >> s;
    if (lazy[i]) {
      apply(i << 1, lazy[i]);
      apply(i << 1 | 1, lazy[i]);
      lazy[i] = 0;
    }
  }
}
void update(int l, int r, int64_t val) {
  l += n, r += n;
  int l0 = l, r0 = r;
  for (; l < r; l >>= 1, r >>= 1) {
    if (l & 1) apply(l++, val);
    if (r & 1) apply(--r, val);
  }
  push_up(l0);
  push_up(r0 - 1);
}
int64_t query(int l, int r) {
  l += n, r += n;
  push_down(l);
  push_down(r - 1);
  int64_t res = -2e9;
  for (; l < r; l >>= 1, r >>= 1) {
    if (l & 1) res = max(res, t[l++]);
    if (r & 1) res = max(res, t[--r]);
  }
  return res;
}
int32_t main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  a.resize(n); t.resize(n << 1); lazy.resize(n);
  h = __lg(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  build();
  cin >> q;
  while (q--) {
    int ty, l, r; cin >> ty >> l >> r;
    if (ty == 1) {
      int64_t val; cin >> val;
      update(l - 1, r, val);
    } else {
      cout << query(l - 1, r) << '\n';
    }
  }
  return 0;
}