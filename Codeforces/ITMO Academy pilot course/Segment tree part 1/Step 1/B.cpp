#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;

int n, q;
int a[maxn];
int64_t t[maxn << 1];

void build() {
  for (int i = 0; i < n; i++) t[n + i] = a[i];
  for (int i = n - 1; i > 0; i--) t[i] = min(t[i << 1], t[i << 1 | 1]);
}
int64_t get(int l, int r) {
  int64_t res = 1e18;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1) res = min(res, t[l++]);
    if (r & 1) res = min(res, t[--r]);
  }
  return res;
}
void update(int p, int val) {
  for (t[p += n] = val; p > 1; p >>= 1) t[p >> 1] = min(t[p], t[p ^ 1]);
}
int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> q;
  for (int i = 0; i < n; i++) cin >> a[i];
  build();
  while (q--) {
    int ty; cin >> ty;
    if (ty == 1) {
      int pos, val; cin >> pos >> val;
      update(pos, val);      
    } else {
      int l, r; cin >> l >> r;
      cout << get(l, r) << '\n';
    }
  }  
  return 0;
}