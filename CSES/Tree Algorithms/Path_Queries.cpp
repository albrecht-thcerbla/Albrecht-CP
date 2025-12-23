#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

const int mod = 1e9 + 7;
const int maxn = 2e5 + 7;
const int64_t inf = 1e18;

int n, q;
vector<int> adj[maxn];
int a[maxn], par[maxn], h[maxn], heavy[maxn], head[maxn], pos[maxn], SZ[maxn], curpos = 0;
int64_t t[maxn << 1];
int base[maxn];

int dfs1(int u, int p) {
  par[u] = p;
  SZ[u] = 1;
  int mx = 0;
  for (int v : adj[u]) {
    if (v != p) {
      h[v] = h[u] + 1;
      int cnt_sz = dfs1(v, u);
      SZ[u] += cnt_sz;
      if (cnt_sz > mx) {
        mx = cnt_sz;
        heavy[u] = v;
      }
    }
  }
  return SZ[u];
}
void dfs2(int u, int curh) {
  head[u] = curh;
  pos[u] = ++curpos;
  base[curpos] = a[u];
  if (heavy[u]) dfs2(heavy[u], curh);
  for (int v : adj[u]) {
    if (v != par[u] && v != heavy[u]) dfs2(v, v);
  }
}
void build() {
  for (int i = 1; i <= n; i++) t[i + n] = base[i];
  for (int i = n - 1; i > 0; i--) t[i] = t[i << 1] + t[i << 1 | 1];
}
void upd(int p, int val) {
  for (t[p += n] = val; p > 1; p >>= 1) t[p >> 1] = t[p] + t[p ^ 1];
}
int64_t get(int l, int r) {
  int64_t res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1) res += t[l++];
    if (r & 1) res += t[--r];
  }
  return res;
}
int64_t get_path(int u, int v) {
  int64_t res = 0;
  while (head[u] != head[v]) {
    if (h[head[u]] < h[head[v]]) swap(u, v);
    res += get(pos[head[u]], pos[u] + 1);
    u = par[head[u]];
  }
  if (h[u] > h[v]) swap(u, v);
  res += get(pos[u], pos[v] + 1);
  return res;
}
int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cin.exceptions(cin.failbit);
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i < n; i++) {
    int u, v; cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  dfs1(1, 0);
  dfs2(1, 1);
  build();
  while (q--) {
    int ty; cin >> ty;
    if (ty == 1) {
      int s, x; cin >> s >> x;
      upd(pos[s], x);
    } else {
      int s; cin >> s;
        cout << get_path(1, s) << '\n';
    }
  }
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}