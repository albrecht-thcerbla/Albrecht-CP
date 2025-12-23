#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define int int64_t

const int mod = 1e9 + 7;
const int maxn = 2e5 + 7;
const int64_t inf = 1e18;

int n, q, a[maxn], in[maxn], out[maxn], cnt;
vector<int> adj[maxn];
vector<int64_t> t(maxn << 1, 0);

void dfs(int u, int p) {
  in[u] = ++cnt;
  for (int v : adj[u]) {
    if (v != p) dfs(v, u);
  }
  out[u] = cnt;
}
void upd(int p, int val) {
  for (t[p += n] = val; p > 1; p >>= 1) t[p >> 1] = t[p] + t[p ^ 1];
}
int get(int l, int r) {
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1) res += t[l++];
    if (r & 1) res += t[--r];
  }
  return res;
}
int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cin.exceptions(cin.failbit);
  // freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  // freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i < n; i++) {
    int u, v; cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  dfs(1, -1);
  for (int i = 1; i <= n; i++) upd(in[i], a[i]);
  while (q--) {
    int ty; cin >> ty;
    if (ty == 1) {
      int u, x; cin >> u >> x;
      upd(in[u], x);
    } else {
      int u; cin >> u;
      cout << get(in[u], out[u] + 1) << '\n';
    }
  }
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}