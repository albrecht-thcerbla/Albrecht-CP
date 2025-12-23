#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
const int64_t inf = 1e18;

// h[u] + h[v] - 2 * h[p]; trong do p = lca(u, v)

int n, q;
vector<int> adj[maxn];

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  cin >> n >> q;
  for (int i = 1; i < n; i++) {
    int a, b; cin >> a >> b;
    
  }  
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}