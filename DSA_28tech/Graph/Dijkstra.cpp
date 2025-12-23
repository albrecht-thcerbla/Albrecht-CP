#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
const int64_t inf = 1e18;

int n, m;
vector<pair<int64_t, int>> adj[maxn];
vector<int64_t> d, par;

void dijkstra(int s) {
  d.assign(n + 1, inf);
  par.assign(n + 1, -1);
  priority_queue<pair<int64_t, int>> pq;
  d[s] = 0;
  pq.emplace(-d[s], s);
  while (sz(pq)) {
    int u = pq.top().second;
    int64_t dist = -pq.top().first;
    pq.pop();
    if (dist > d[u]) continue;
    for (auto [v, w] : adj[u]) {
      if (d[v] > d[u] + w) {
        d[v] = d[u] + w;
        par[v] = u;
        pq.emplace(-d[v], v);
      }
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x, y, w; cin >> x >> y >> w;
    adj[x].emplace_back(y, w);
    adj[y].emplace_back(x, w);
  }
  dijkstra(1);
  if (d[n] == inf) return cout << -1 << '\n', 0;
  vector<int> path;
  for (int i = n; i != -1; i = par[i]) path.emplace_back(i);
  reverse(all(path));
  for (int i = 0; i < sz(path); i++) cout << path[i] << " ";
  return 0;
}
