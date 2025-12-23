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
  int n, m; cin >> n >> m;
  vector<vector<pair<int, int>>> adj(n + 1), radj(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v, w; cin >> u >> v >> w;
    adj[u].emplace_back(v, w);
    radj[v].emplace_back(u, w);
  }
  auto dijkstra = [&](vector<vector<pair<int, int>>>& a) {
    vector<int64_t> dist(n + 1, inf);
    priority_queue<pair<int64_t, int>> pq;
    dist[1] = 0;
    pq.emplace(0, 1);
    while (sz(pq)) {
      auto [d, u] = pq.top(); pq.pop();
      if (-d > dist[u]) continue;
      for (auto [v, w] : a[u]) {
        if (dist[u] + w < dist[v]) {
          dist[v] = dist[u] + w;
          pq.emplace(-dist[v], v);
        }
      }
    }
    return dist;
  };
  vector<int64_t> d1 = dijkstra(adj), d2 = dijkstra(radj);
  for (int i = 2; i <= n; i++) cout << (d1[i] == inf || d2[i] == inf ? -1 : d1[i] + d2[i]) << '\n';
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}

