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
  int n, m; cin >> n >> m;
  vector<vector<array<int, 3>>> adj(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v, l, c; cin >> u >> v >> l >> c;
    adj[u].emplace_back(array<int, 3>{v, l, c});
    adj[v].emplace_back(array<int, 3>{u, l, c});
  }
  auto dijkstra = [&]() {
    vector<int> dist(n + 1, inf), b(n + 1, -inf);
    priority_queue<pair<int, int>> pq;
    dist[1] = 0;
    b[1] = 0;
    pq.emplace(0, 1);
    while (sz(pq)) {
      auto [d, u] = pq.top(); pq.pop();
      if (-d > dist[u]) continue;
      for (auto [v, w, beauty] : adj[u]) {
        if (dist[u] + w < dist[v]) {
          dist[v] = dist[u] + w;
          b[v] = b[u] + beauty;
          pq.emplace(-dist[v], v);
        } else if (dist[u] + w == dist[v]) {
          b[v] = max<int64_t>(b[v], b[u] + beauty);
        }
      }
    }
    if (dist[n] == inf) cout << -1 << '\n';
    else cout << dist[n] << " " << b[n] << '\n';
  };
  dijkstra();
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}

