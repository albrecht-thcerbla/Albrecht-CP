#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

const int mod = 1e9 + 7;
const int maxn = 2e5 + 7;
const int64_t inf = 1e18;

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cin.exceptions(cin.failbit);
  int tt; cin >> tt;
  while (tt--) {
    int n, a, b; cin >> n >> a >> b;
    vector<int> adj[maxn], deg(maxn, 0);
    vector<bool> cycle(maxn, false);
    for (int i = 0; i < n; i++) {
      int x, y; cin >> x >> y;
      adj[x].emplace_back(y);
      adj[y].emplace_back(x);
      deg[x]++, deg[y]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) if (deg[i] == 1) q.emplace(i);
    vector<bool> vis(n + 1, false);
    while (sz(q)) {
      int u = q.front(); q.pop();
      vis[u] = true;
      for (int v : adj[u]) {
        if (!vis[v]) {
          deg[v]--;
          if (deg[v] == 1) q.emplace(v);
        }
      }
    }
    for (int i = 1; i <= n; i++) if (!vis[i]) cycle[i] = true;
    vector<int> da, db;
    auto bfs = [&](int st, int n, vector<int>& d) -> void {
      d.assign(n + 1, 1e9);
      queue<int> q;
      d[st] = 0;
      q.emplace(st);
      while (sz(q)) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
          if (d[v] > d[u] + 1) {
            d[v] = d[u] + 1;
            q.emplace(v);
          }
        }
      }
    };
    bfs(a, n, da);
    bfs(b, n, db);
    bool ok = false;
    for (int i = 1; i <= n; i++) {
      if (cycle[i]) {
        if (db[i] < da[i]) {
          ok = true;
          break;
        }
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}

