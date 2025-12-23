#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  int tt; cin >> tt;
  while (tt--) {
    int n; cin >> n;
    vector<vector<int>> g(n + 1);
    vector<int> indeg(n + 1, 0);
    for (int i = 0; i < n - 1; i++) {
      int u, v; cin >> u >> v;
      int x, y; cin >> x >> y;
      if (x > y) {
        g[v].emplace_back(u);
        ++indeg[u];
      } else {
        g[u].emplace_back(v);
        ++indeg[v];
      }
    }
    // Kahn sort
    queue<int> q;
    for (int i = 1; i <= n; i++) if (!indeg[i]) q.emplace(i);
    vector<int> topo;
    while (!q.empty()) {
      int v = q.front(); q.pop();
      topo.emplace_back(v);
      for (auto t : g[v]) if (!--indeg[t]) q.emplace(t);
    }
    vector<int> p(n + 1);
    for (int i = 0; i < sz(topo); i++) p[topo[i]] = i + 1;
    for (int i = 1; i <= n; i++) {
      if (i > 1) cout << " ";
      cout << p[i];
    }
    cout << '\n';
  }
  return 0;
}