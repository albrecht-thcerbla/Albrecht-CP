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
  int n, r, l, c; cin >> n >> l >> r >> c;
  int st, en; cin >> st >> en;
  vector<int> color(n + 1);
  for (int i = 1; i <= n; i++) cin >> color[i];
  map<int, int> mp;
  int cnt = 0;
  for (int i = 1; i <= n; i++) if (!mp.count(color[i])) mp[color[i]] = ++cnt;
  int N = n + cnt;
  vector<vector<pair<int, int>>> adj(N + 1);
  adj[1].emplace_back(2, r);
  adj[n].emplace_back(n - 1, l);
  for (int i = 2; i <= n - 1; i++) {
    adj[i].emplace_back(i + 1, r);
    adj[i].emplace_back(i - 1, l);
  }
  for (int i = 1; i <= n; i++) {
    adj[i].emplace_back(n + mp[color[i]], c);
    adj[n + mp[color[i]]].emplace_back(i, 0);
  }
  auto dijkstra = [&](int s) {
    vector<int64_t> dist(N + 1, inf);
    priority_queue<pair<int64_t, int>> pq;
    dist[s] = 0;
    pq.emplace(0, s);
    while (sz(pq)) {
      auto [d, u] = pq.top(); pq.pop();
      if (-d > dist[u]) continue;
      for (auto [v, w] : adj[u]) {
        if (dist[u] + w < dist[v]) {
          dist[v] = dist[u] + w;
          pq.emplace(-dist[v], v);
        }
      }
    }
    cout << dist[en] << '\n';
  };
  dijkstra(st);
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}

