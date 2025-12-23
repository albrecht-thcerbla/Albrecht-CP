#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
const int64_t inf = 1e18;

int n, lim, used;
vector<int> p, pos;

void query(int x, int y) {
  cout << "? " << x << " " << y << '\n';
  cout.flush();
  int u, v; cin >> u >> v;
  swap(p[u], p[v]);
  pos[p[u]] = u;
  pos[p[v]] = v;
  ++used;
}
bool ok() {
  for (int i = 1; i <= n; i++) if (p[i] != i) return false;
  return true;
}
int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cin.exceptions(cin.failbit);
  int tt; cin >> tt;
  while (tt--) {
    int n; cin >> n;
    p.resize(n + 1), pos.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> p[i], pos[p[i]] = i;
    lim = (2.5 * n) + 800;
    used = 0;
    for (int i = 1; i <= n && used < lim; i++) {
      while (p[i] != i && used < lim) {
        if (i == pos[i]) break;
        query(i, pos[i]);
      }
    }
    cout << "!" << '\n';
    cout.flush();
  }
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}

