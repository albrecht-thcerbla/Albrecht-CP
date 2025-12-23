#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define int int64_t

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
const int64_t inf = 1e18;

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cin.exceptions(cin.failbit);
  int tt; cin >> tt;
  while (tt--) {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(all(a));
    a.erase(unique(all(a)), a.end());
    n = sz(a);
    int mx = a.back();
    set<int> se(all(a));
    vector<int> g;
    for (int i = 0; i < n; i++) {
      bool ok = true;
      for (int j = a[i]; j <= mx; j += a[i]) if (!se.count(j)) {
        ok = false;
        break;
      }
      if (!ok) continue;
      if ((k / a[i]) * a[i] > mx) continue;
      g.emplace_back(a[i]);
    }
    if (g.empty()) {
      cout << -1 << '\n';
      continue;
    }
    sort(all(g));
    vector<char> c(sz(a));
    for (int i = 0; i < sz(g); i++) {
      for (int j = g[i]; j <= mx; j += g[i]) {
        auto it = lower_bound(all(a), j);
        if (it != a.end() && *it == j) c[it - a.begin()] = 1;
      }
    }
    if (count(all(c), 0)) {
      cout << -1 << '\n';
      continue;
    }
    vector<char> d(sz(g));
    int gmax = g.back();
    for (int i = 0; i < sz(g); i++) if (!d[i]) {
      for (int j = g[i] << 1; j <= gmax; j += g[i]) {
        auto it = lower_bound(g.begin() + i + 1, g.end(), j);
        if (it != g.end() && *it == j) d[it - g.begin()] = 1;
      }
    }
    vector<int> ans;
    for (int i = 0; i < sz(g); i++) if (!d[i]) ans.emplace_back(g[i]);
    cout << sz(ans) << '\n';
    for (int i = 0; i < sz(ans); i++) cout << ans[i] << " ";
    cout << '\n';
  }
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}

