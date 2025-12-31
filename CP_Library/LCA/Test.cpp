#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

const int mod = 1e9 + 7;
const int maxn = 2e5 + 5;
const int64_t inf = 1e18;

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cin.exceptions(cin.failbit);
  int n, q; cin >> n >> q;
  vector<vector<int>> adj(maxn);
  vector<vector<int>> par(20, vector<int>(maxn)); // par[i][u] = cha thu 2^i cua u
  vector<int> h(maxn, 0);
  for (int i = 1; i < n; i++) {
    int x, y; cin >> x >> y;
    adj[x].emplace_back(y);
    adj[y].emplace_back(x);
  }
  auto dfs = [&](auto self, int u) -> void {
    for (auto v : adj[u]) {
      if (v == par[0][u]) continue;
      par[0][v] = u;
      for (int i = 1; i <= 19; i++) par[i][v] = par[i - 1][par[i - 1][v]];
      h[v] = h[u] + 1;
      self(self, v);
    }
  };
  auto lca = [&](int u, int v) -> int {
    if (h[u] < h[v]) swap(u, v);
    int k = h[u] - h[v];
    for (int i = 0; i < 20; i++) if (k & (1 << i)) u = par[i][u];
    if (u == v) return u;
    for (int i = 19; ~i; i--) {
      if (par[i][u] != par[i][v]) {
        u = par[i][u];
        v = par[i][v];
      }
    }
    return par[0][u];
  };
  dfs(dfs, 1);
  while (q--) {
    int u, v; cin >> u >> v;
    cout << lca(u, v) << '\n';
  }
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}

