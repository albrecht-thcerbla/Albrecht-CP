#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define int int64_t

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;

int n, q, h;
vector<int> a;
vector<int> t, lazy_add, lazy_mul, lazy_set, len;
vector<bool> has_set;

void build() {
  for (int i = 0; i < n; i++) t[i + n] = a[i];
  for (int i = n - 1; i > 0; i--) {
    t[i] = (t[i << 1] + t[i << 1 | 1]) % mod;
    len[i] = len[i << 1] + len[i << 1 | 1];
  }
}
void apply(int p, int add, int mul, bool tight, int set_val) {
  if (tight) {
    t[p] = (set_val * len[p]) % mod;
    if (p < n) {
      lazy_add[p] = 0;
      lazy_mul[p] = 1;
      has_set[p] = true;
      lazy_set[p] = set_val;
    }
  } else {
    t[p] = (t[p] * mul + add * len[p]) % mod;
    if (p < n) {
      if (has_set[p]) lazy_set[p] = (lazy_set[p] * mul + add) % mod;
      else {
        lazy_mul[p] = (lazy_mul[p] * mul) % mod;
        lazy_add[p] = (lazy_add[p] * mul + add) % mod;
      }
    }
  }
}
void push_down(int p) {
  for (int s = h; s; s--) {
    int i = p >> s;
    if (has_set[i]) {
      apply(i << 1, 0, 1, true, lazy_set[i]);
      apply(i << 1 | 1, 0, 1, true, lazy_set[i]);
      has_set[i] = false;
      lazy_set[i] = -1;
    }
    if (lazy_mul[i] != 1 || lazy_add[i]) {
      apply(i << 1, lazy_add[i], lazy_mul[i], false, 0);
      apply(i << 1 | 1, lazy_add[i], lazy_mul[i], false, 0);
      lazy_mul[i] = 1;
      lazy_add[i] = 0;
    }
  }
}

void push_up(int p) {
  while (p > 1) {
    p >>= 1;
    if (has_set[p]) t[p] = (lazy_set[p] * len[p]) % mod;
    else {
      t[p] = (t[p << 1] + t[p << 1 | 1]) % mod;
      if (lazy_mul[p] != 1 || lazy_add[p]) t[p] = (t[p] * lazy_mul[p] + lazy_add[p] * len[p]) % mod;
    }
  }
}
void update(int l, int r, int add, int mul, bool tight, int set_val = 0) {
  int ll = l + n, rr = r + n;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1) apply(l++, add, mul, tight, set_val);
    if (r & 1) apply(--r, add, mul, tight, set_val);
  }
  push_up(ll);
  push_up(rr - 1);
}
int get(int l, int r) {
  l += n, r += n;
  push_down(l);
  push_down(r - 1);
  int res = 0;
  for (; l < r; l >>= 1, r >>= 1) {
    if (l & 1) (res += t[l++]) %= mod;
    if (r & 1) (res += t[--r]) %= mod;
  }
  return res;
}
int32_t main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  cin >> n >> q;
  h = 1 << (__lg(n)) - 1;
  a.resize(n);
  t.assign(n << 1, 0);
  lazy_add.assign(n, 0);
  lazy_mul.assign(n, 1);
  lazy_set.assign(n, -1);
  has_set.assign(n, false);
  len.resize(n << 1, 1);
  for (int i = 0; i < n; i++) cin >> a[i];
  build();
  while (q--) {
    int ty, l, r, x; cin >> ty >> l >> r;
    if (ty == 1) {
      cin >> x;
      update(l - 1, r, x, 1, false);
    } else if (ty == 2) {
      cin >> x;
      update(l - 1, r, 0, x, false);
    } else if (ty == 3) {
      cin >> x;
      update(l - 1, r, 0, 1, true, x);
    } else cout << get(l - 1, r) << '\n';
  }
  return 0;
}