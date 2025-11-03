#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
const int64_t inf = 1e18;

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  int n, m; cin >> n >> m;
  vector<vector<pair<int, int>>> adj(n + 1);
  for (int i = 0; i < m; i++) {
    int a, b, c; cin >> a >> b >> c;
    adj[a].emplace_back(b, c);
  }
  vector<vector<int64_t>> d(n + 1, vector<int64_t>(2, inf));
  priority_queue<tuple<int64_t, int, int>> pq;
  d[1][0] = 0;
  pq.emplace(0, 1, 0);
  while (sz(pq)) {
    auto [du, u, used] = pq.top(); pq.pop();
    du = -du;
    if (du != d[u][used]) continue;
    for (auto [v, w] : adj[u]) {
      if (d[v][used] > du + w) {
        d[v][used] = du + w;
        pq.emplace(-d[v][used], v, used);
      }
      if (!used && d[v][1] > du + w / 2) {
        d[v][1] = du + w / 2;
        pq.emplace(-d[v][1], v, 1);
      }
    }
  }
  cout << d[n][1] << '\n';
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}