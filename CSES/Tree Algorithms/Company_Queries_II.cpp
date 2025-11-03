#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)

const int mod = 1e9 + 7;
const int maxn = 2e5 + 7;
const int64_t inf = 1e18;

int n, q, p[20][maxn], h[maxn];
vector<int> adj[maxn];

void dfs(int u) {
  for (auto v : adj[u]) {
    if (v != p[0][u]) {
      p[0][v] = u;
      for (int i = 1; i <= 19; i++) p[i][v] = p[i - 1][p[i - 1][v]];
      h[v] = h[u] + 1;
      dfs(v);
    }
  }
}
int lca(int u, int v) {
  if (h[v] > h[u]) swap(u, v); // u sâu hơn v
  int k = h[u] - h[v];
  for (int i = 19; ~i; --i) if ((k >> i) & 1) u = p[i][u];
  if (u == v) return u;
  for (int i = 19; ~i; --i) {
    if (p[i][u] != p[i][v]) {
      u = p[i][u];
      v = p[i][v];
    }
  }
  return p[0][u]; // p[0][v]
}
int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  // freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  // freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  cin >> n >> q;
  for (int i = 2; i <= n; i++) {
    int x; cin >> x;
    adj[x].emplace_back(i);
    adj[i].emplace_back(x);
  }
  dfs(1);
  while (q--) {
    int u, v; cin >> u >> v;
    cout << lca(u, v) << '\n';
  }
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}