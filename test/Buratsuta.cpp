#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
const int64_t inf = 1e18;

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cin.exceptions(cin.failbit);
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  int tt; cin >> tt;
  int n, q;
  vector<int> a;
  vector<array<int, 4>> t;
  map<int, vector<int>> mp;
  auto Merge = [&](array<int, 4> a, array<int, 4> b, int c = 0) -> array<int, 4> {
    pair<int, int> v[4];
    if (a[1]) v[c++] = {a[0], a[1]};
    if (a[3]) v[c++] = {a[2], a[3]};
    if (b[1]) v[c++] = {b[0], b[1]};
    if (b[3]) v[c++] = {b[2], b[3]};
    for (int i = 0; i < c; i++) {
      for (int j = i + 1; j < c; j++) {
        if (v[i].first == v[j].first) {
          v[i].second += v[j].second;
          v[j--] = v[--c];
        }
      }
    }
    while (c > 2) {
      int mn = 1e9;
      for (int i = 0; i < c; i++) mn = min(mn, v[i].second);
      for (int i = 0; i < c; i++) v[i].second -= mn;
      for (int i = 0; i < c; i++) if (!v[i].second) v[i] = v[--c];
    }
    array<int, 4> res = {0, 0, 0, 0};
    if (c > 0) res[0] = v[0].first, res[1] = v[0].second;
    if (c > 1) res[2] = v[1].first, res[3] = v[1].second;
    return res;
  };
  auto build = [&]() {
    for (int i = 0; i < n; i++) t[i + n] = {a[i], 1, 0, 0};
    for (int i = n - 1; i; i--) t[i] = Merge(t[i << 1], t[i << 1 | 1]);
  };
  auto get = [&](int l, int r) -> array<int, 4> {
    array<int, 4> resl = {0, 0, 0, 0}, resr = {0, 0, 0, 0};
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) resl = Merge(resl, t[l++]);
      if (r & 1) resr = Merge(t[--r], resr);
    }
    return Merge(resl, resr);
  };
  auto cnt = [&](int x, int l, int r) -> int {
    vector<int> v = mp[x];
    return (upper_bound(all(v), r) - lower_bound(all(v), l));
  };
  while (tt--) {
    cin >> n >> q;
    a.resize(n); t.assign(n << 1, {0, 0, 0, 0}); mp.clear();
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) mp[a[i]].emplace_back(i + 1);
    build();
    while (q--) {
      int l, r; cin >> l >> r;
      array<int, 4> res = get(l - 1, r);
      vector<int> ans, out;
      if (res[1]) ans.emplace_back(res[0]);
      if (res[3]) ans.emplace_back(res[2]);
      for (int i = 0; i < sz(ans); i++) if (cnt(ans[i], l, r) > (r - l + 1) / 3) out.emplace_back(ans[i]);
      if (out.empty()) cout << -1 << '\n';
      else {
        if (sz(out) == 2 && out[0] > out[1]) swap(out[0], out[1]);
        for (int i = 0; i < sz(out); i++) cout << out[i] << " ";
        cout << '\n';
      }
    }
  }
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}