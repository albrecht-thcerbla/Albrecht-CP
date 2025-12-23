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
  int n, m, k; cin >> n >> m >> k;
  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  auto dijkstra = [&]() {
    vector<int> dist(n + 1, -1);
    vector<pair<int, int>> pl(k);
    int maxr = 0;
    for (int i = 0; i < k; i++) {
      int p, r; cin >> p >> r;
      r = min(r, n);
      pl[i] = make_pair(p, r);
      maxr = max(maxr, r);
    }
    vector<vector<int>> buckets(maxr + 1);
    for (auto [p, r] : pl) {
      if (r > dist[p]) {
        dist[p] = r;
        buckets[r].emplace_back(p);
      }
    }
    for (int i = maxr; i > 0; i--) {
      for (int u : buckets[i]) {
        if (dist[u] != i) continue;
        for (int v : adj[u]) {
          if (i - 1 > dist[v]) {
            dist[v] = i - 1;
            buckets[i - 1].emplace_back(v);
          }
        }
      }
    }
    for (int i = 1; i <= n; i++) cout << (dist[i] >= 0 ? 1 : 0);
  };
  dijkstra();
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}

