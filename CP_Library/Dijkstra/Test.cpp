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
  vector<vector<pair<int, int>>> adj(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v, w; cin >> u >> v >> w;
    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w);
  } 
  //int s; cin >> s;
  auto dijkstra = [&](int s) {
    vector<int64_t> dist(n + 1, inf), par(n + 1, -1);
    priority_queue<pair<int64_t, int>> pq;
    dist[s] = 0;
    pq.emplace(0, s);
    while (sz(pq)) {
      auto [d, u] = pq.top(); pq.pop();
      if (-d > dist[u]) continue;
      for (auto [v, w] : adj[u]) {
        if (dist[u] + w < dist[v]) {
          dist[v] = dist[u] + w;
          par[v] = u;
          pq.emplace(-dist[v], v);
        }
      }
    }
    if (dist[n] == inf) return void (cout << -1 << '\n');
    vector<int> path;
    for (int i = n; i != -1; i = par[i]) path.emplace_back(i);
    reverse(all(path));
    for (int i = 0; i < sz(path); i++) cout << path[i] << " ";
  };
  dijkstra(1);
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}

