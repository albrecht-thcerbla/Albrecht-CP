#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int maxn = 31;

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tt; cin >> tt;
  while (tt--) {
    int n, q; cin >> n >> q;
    vector<int64_t> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int64_t> mincost(maxn, 4e18);
    for (int k = 0; k < maxn; k++) {
      int64_t block = 1 << (k + 1);
      int64_t need = 1 << k;
      int64_t best = 4e18;
      for (int i = 0; i < n; i++) {
        int64_t r = a[i] % block;
        if (r >= need) {
          best = 0;
          break;
        } else best = min(best, need - r);
      }
      mincost[k] = best;
    }
    int zero = 0;
    vector<int64_t> cost;
    for (int k = 0; k < maxn; k++) {
      if (!mincost[k]) ++zero;
      else cost.emplace_back(mincost[k]);
    }
    sort(all(cost));
    while (q--) {
      int64_t b; cin >> b;
      int cnt = zero;
      for (int64_t c : cost) {
        if (c <= b) {
          b -= c;
          ++cnt;
        } else break;
      }
      cout << cnt << '\n';
    }
  }
  return 0;
}