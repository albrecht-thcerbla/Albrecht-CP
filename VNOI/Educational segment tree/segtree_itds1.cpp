#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;

/**
 * 1 i v   : chang the i-th number to v.
 * 2 L R k : print the smallest number greater than or equal to k in the range L to R.
 * 
 * 
 * */
int n, m;
vector<int> a;
vector<multiset<int>> t;

void build() {
  for (int i = 0; i < n; i++) t[i + n].insert(a[i]);
  for (int i = n - 1; i > 0; i--) {
    t[i].insert(all(t[i << 1]));
    t[i].insert(all(t[i << 1 | 1]));
  }
}
void modify(int p, int old_val, int new_val) {
  for (t[p += n].erase(t[p].find(old_val)), t[p].insert(new_val); p > 1; p >>= 1) {
    t[p >> 1].erase(t[p >> 1].find(old_val));
    t[p >> 1].insert(new_val);
  }
}
int get(int l, int r, int k) {
  int res = INT_MAX;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1) {
      auto it = t[l].lower_bound(k);
      if (it != t[l].end()) res = min(res, *it);
      ++l;
    }
    if (r & 1) {
      --r;
      auto it = t[r].lower_bound(k);
      if (it != t[r].end()) res = min(res, *it);
    }
  }
  return (res == INT_MAX) ? -1 : res;
}
int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  a.resize(n); t.resize(n << 1);
  for (int i = 0; i < n; i++) cin >> a[i];
  build();
  while (m--) {
    int ty; cin >> ty;
    if (ty == 1) {
      int i, v; cin >> i >> v;
      modify(i - 1, a[i - 1], v);
      a[i - 1] = v;
    } else {
      int l, r, k; cin >> l >> r >> k;
      cout << get(l - 1, r, k) << '\n';
    }
  }
  return 0;
}