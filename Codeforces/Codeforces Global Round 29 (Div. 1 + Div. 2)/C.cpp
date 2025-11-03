#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tt; cin >> tt;
  while (tt--) {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> id(n, -1);
    int m = 0;
    for (int i = 0; i < n; i++) if (s[i] == '0') id[i] = m++;
    if (!m) {
      cout << "YES" << '\n';
      continue;
    }
    vector<vector<int>> g(m << 1), gr(m << 1);
    auto add = [&](int u, int v) {
      g[u].emplace_back(v);
      gr[v].emplace_back(u); 
    };
    auto lit = [&](int var, bool val) {
      return (var << 1) + (val ? 1 : 0);
    };
    auto add_clause = [&](int varA, bool valA, int varB, bool valB) {
      int A = lit(varA, valA), B = lit(varB, valB);
      add(A ^ 1, B);
      add(B ^ 1, A);
    };
    auto add_unit = [&](int var, bool val) {
      add_clause(var, val, var, val);
    };
    for (int p = 0; p < n; p++) {
      if (s[p] == '1') {
        bool l = (p - 1 >= 0 && s[p - 1] == '0');
        bool r = (p + 1 < n && s[p + 1] == '0');
        if (l && r) add_clause(id[p - 1], false, id[p + 1], true);
        else if (l) add_unit(id[p - 1], false);
        else if (r) add_unit(id[p + 1], true);
      }
    }
    vector<int> o;
    vector<char> vis(m << 1, 0);
    for (int i = 0; i < (m << 1); i++) {
      if (vis[i]) continue;
      vector<pair<int, int>> stk;
      stk.emplace_back(i, 0);
      while (!stk.empty()) {
        int u = stk.back().first;
        int& it = stk.back().second;
        if (!vis[u]) vis[u] = 1;
        if (it < sz(g[u])) {
          int v = g[u][it++];
          if (!vis[v]) stk.emplace_back(v, 0);
        } else {
          o.emplace_back(u);
          stk.pop_back();
        }
      }
    }
    vector<int> comp(m << 1, -1);
    int cid = 0;
    for (int i = (m << 1) - 1; ~i; --i) {
      int u = o[i];
      if (comp[u] != -1) continue;
      stack<int> stk;
      stk.emplace(u);
      comp[u] = cid;
      while (!stk.empty()) {
        int v = stk.top(); stk.pop();
        for (int w : gr[v]) {
          if (comp[w] == -1) {
            comp[w] = cid;
            stk.emplace(w);
          }
        }
      }
      ++cid;
    }
    bool ok = true;
    for (int i = 0; i < m; i++) if (comp[i << 1] == comp[i << 1 | 1]) {
      ok = false;
      break;
    }
    if (ok) cout << "YES" << '\n';
    else cout << "NO" << '\n';
  }
  return 0;
}