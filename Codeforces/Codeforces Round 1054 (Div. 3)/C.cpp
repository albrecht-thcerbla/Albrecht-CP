#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  int tt; cin >> tt;
  while (tt--) {
    int n, k; cin >> n >> k;
    vector<int> a(n + 1, 0);
    for (int i = 0; i < n; i++) {
      int x; cin >> x;
      if (x >= 0 && x <= n) ++a[x];
    }
    int miss = 0;
    for (int i = 0; i < k; i++) {
      if (!a[i]) ++miss;
    }
    cout << max(miss, a[k]) << '\n';
  }
  return 0;
}