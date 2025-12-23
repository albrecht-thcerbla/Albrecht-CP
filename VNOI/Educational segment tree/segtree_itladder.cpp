#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int MOD = 1e9 + 7;
const int maxn = 1e5 + 7;

int n, m;

int64_t t[(maxn << 1)];
int64_t lazyadd[maxn];
int64_t lazyinc[maxn];

int64_t sum(int x) {
  return (int64_t) (x * (x + 1) >> 1);
}
void apply(int p, int64_t b, int64_t a, int len) {
  t[p] = (t[p] + len * b + sum(len - 1) * a) % MOD;
  if (p < n) {
    (lazyadd[p] += b) %= MOD;
    (lazyinc[p] += a) %= MOD;
  }
}
void push(int l, int r) {
  int h = __lg(n);
  int num_child = 1 << (h - 1);
  l += n, r += n - 1;
  for (int s = h; s; --s, num_child >>= 1) {
    for (int i = l >> s; i <= (r >> s); i++) {
      if (lazyadd[i] || lazyinc[i]) {
        apply(i << 1, lazyadd[i], lazyinc[i], num_child);
        apply(i << 1 | 1, (lazyadd[i] + lazyinc[i] * num_child) % MOD, lazyinc[i], num_child);
        lazyadd[i] = lazyinc[i] = 0;
      }
    }
  }
}
void pull(int l, int r, int len = 1) {
  l += n, r += n - 1;
  while (l > 1) {
    l >>= 1, r >>= 1, len <<= 1;
    for (int i = r; i >= l; --i) t[i] = (t[i << 1] + t[i << 1 | 1] + len * lazyadd[i] + sum(len - 1) * lazyinc[i]) % MOD;
  }
}
void update(int l, int r, int64_t b, int64_t a) {
  int ll = l, rr = r;
  int left = 0, right = r - l, len = 1;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1, len <<= 1) {
    if (l & 1) apply(l++, (b + a * left) % MOD, a, len), left += len;
    if (r & 1) apply(--r, (b + a * (right - len)) % MOD, a, len), right -= len;
  }
  pull(ll, ll + 1);
  pull(rr - 1, rr);
}
int64_t get(int l, int r) {
  push(l, l + 1);
  push(r - 1 , r);
  int64_t res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1) (res += t[l++]) %= MOD;
    if (r & 1) (res += t[--r]) %= MOD;
  }
  return res;
}
int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  cin >> n >> m;
  while (m--) {
    int ty, l, r; cin >> ty >> l >> r;
    if (ty == 1) {
      int a, b; cin >> a >> b;
      update(l - 1, r, b, a);
    } else cout << get(l - 1, r) << '\n';
  }
  return 0;
}