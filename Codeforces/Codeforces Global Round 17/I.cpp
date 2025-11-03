#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int maxn = 600006;

int n, sg[maxn], pre[maxn], bad[maxn], root = 1;
vector<int> g[maxn];
set<int> son[maxn];

void dfs(int u, int p) {
  pre[u] = p;
  for (int v : g[u]) {
    if (v != p) {
      dfs(v, u);
      son[u].insert(v);
    }
  }
}
void calc(int u) {
  for (int v : son[u]) {
    calc(v);
    sg[u] ^= sg[v] + 1;
  }
}
void Merge(vector<int> chain) {
  for (int v : chain) bad[v] = 1;
  for (int i = 0; i + 1 < sz(chain); i++) {
    son[chain[i]].erase(chain[i + 1]);
    sg[chain[i]] ^= sg[chain[i + 1]] + 1;
  }
  for (int i = 1; i < sz(chain); i++) {
    int u = chain[i];
    if (sz(son[u]) > sz(son[root])) swap(u, root);
    for (int v : son[u]) {
      pre[v] = root;
      son[root].insert(v);
      sg[root] ^= sg[v] + 1;
    }
    son[u].clear();
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n - 1; i++) {
    int u, v; cin >> u >> v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  dfs(1, 0);
  calc(1);
  cout << (sg[root] ? '1' : '2');
  int ori = n;
  for (int i = 2; i <= ori; i++) {
    if (bad[i] == 1) {
      cout << (sg[root] ? '1' : '2');
      continue;    
    }
    vector<int> chain;
    int u = i;
    while (u != root) {
      chain.emplace_back(u);
      u = pre[u];
    }
    chain.emplace_back(root);
    reverse(all(chain));
    if (sz(chain) % 2 == 0) {
      son[root].insert(++n);
      sg[n] = 0;
      sg[root] ^= 1;
    }
    Merge(chain);
    cout << (sg[root] ? '1' : '2');
  }
  return 0;
}