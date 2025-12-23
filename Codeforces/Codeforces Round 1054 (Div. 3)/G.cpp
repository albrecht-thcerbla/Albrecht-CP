#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;

int n, q;
vector<int> a;
vector<array<int, 4>> t;
map<int, vector<int>> mp;

array<int, 4> Merge(array<int, 4> a, array<int, 4> b) {
  pair<int,int> v[4];
  int c = 0;
  if (a[1]) v[c++] = {a[0], a[1]};
  if (a[3]) v[c++] = {a[2], a[3]};
  if (b[1]) v[c++] = {b[0], b[1]};
  if (b[3]) v[c++] = {b[2], b[3]};
  for (int i = 0; i < c; i++) {
    for (int j = i + 1; j < c; j++) {
      if (v[i].first == v[j].first) {
        v[i].second += v[j].second;
        v[j] = v[--c];
        j--;
      }
    }
  }
  while (c > 2) {
    int mn = INT_MAX;
    for (int i = 0; i < c; i++) mn = min(mn, v[i].second);
    for (int i = 0; i < c; i++) v[i].second -= mn;
    for (int i = 0; i < c;) {
      if (v[i].second == 0) v[i] = v[--c];
      else i++;
    }
  }
  array<int, 4> r = {0, 0, 0, 0};
  if (c > 0) r[0] = v[0].first, r[1] = v[0].second;
  if (c > 1) r[2] = v[1].first, r[3] = v[1].second;
  return r;
}
void build() {
  t.assign(n << 1, {0, 0, 0, 0});
  for (int i = 0; i < n; i++) t[i + n] = {a[i], 1, 0, 0};
  for (int i = n - 1; i; i--) t[i] = Merge(t[i << 1], t[i << 1 | 1]);
}
array<int, 4> get(int l, int r) {
  array<int, 4> ll = {0, 0, 0, 0}, rr = {0, 0, 0, 0};
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1) ll = Merge(ll, t[l++]);
    if (r & 1) rr = Merge(t[--r], rr);
  }
  return Merge(ll, rr);
}

int cnt(int x, int l, int r) {
  auto& v = mp[x];
  return upper_bound(all(v), r) - lower_bound(all(v), l);
}
int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tt; cin >> tt;
  while (tt--) {
    cin >> n >> q;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    mp.clear();
    for (int i = 0; i < n; i++) mp[a[i]].emplace_back(i + 1);
    build();
    while (q--) {
      int l, r; cin >> l >> r;
      auto res = get(l - 1, r);
      int need = (r - l + 1) / 3;
      vector<int> ans;
      if (res[1]) ans.emplace_back(res[0]);
      if (res[3] && res[2] != res[0]) ans.emplace_back(res[2]); 
      vector<int> out;
      for (int i = 0; i < sz(ans); i++)  if (cnt(ans[i], l, r) > need) out.emplace_back(ans[i]);
      if (out.empty()) cout << -1 << '\n';
      else {
        if (out.size() == 2 && out[0] > out[1]) swap(out[0], out[1]);
        for (int i = 0; i < sz(out); i++) cout << out[i] << " ";
        cout << '\n';
      }
    }
  }
  return 0;
}
