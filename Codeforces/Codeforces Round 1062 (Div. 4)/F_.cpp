#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define int int64_t

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
const int64_t inf = 1e18;

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cin.exceptions(cin.failbit);
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  int tt; cin >> tt;
  while (tt--) {
    int n, k; cin >> n >> k;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
      int u, v; cin >> u >> v;
      adj[u].emplace_back(v);
      adj[v].emplace_back(u);
    }
    vector<int> p(n + 1, 0), par;
    stack<int> st;
    st.emplace(1);
    p[1] = -1;
    while (st.size()) {
      int v = st.top(); st.pop();
      par.emplace_back(v);
      for (auto u : adj[v]) {
        if (u == p[v]) continue;
        p[u] = v;
        st.emplace(u);
      }
    }
    vector<int> sz(n + 1, 1);
    for (int i = par.size() - 1; ~i; --i) {
      int v = par[i];
      for (auto u : adj[v]) {
        if (p[u] == v) sz[v] += sz[u];
      }
    }
    int ans = n;
    for (int i = 2; i <= n; i++) {
      int pp = p[i];
      if (sz[i] >= k) ans += (n - sz[i]);
      if (n - sz[i] >= k) ans += sz[i];
    }
    cout << ans << '\n';
  }
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}