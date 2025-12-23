#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
const int64_t inf = 1e18;

int n, m;
vector<pair<int64_t, int>> adj[maxn];

void dijkstra(int s) {
  vector<int64_t> d(n + 1, inf);
  priority_queue<pair<int64_t, int>> pq; // kc - u
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
        pq.emplace(-d[v], v);
      }
    }
  }
  for (int i = 1; i <= n; i++) cout << d[i] << " ";
}
int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x, y, w; cin >> x >> y >> w;
    adj[x].emplace_back(y, w);
  }
  dijkstra(1);
  return 0;
}
