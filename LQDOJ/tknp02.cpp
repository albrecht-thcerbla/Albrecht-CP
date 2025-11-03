#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, k; cin >> n >> k;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= k; i++) {
    int x; cin >> x;
    int l = 0, r = n + 1;
    while (r - l > 1) {
      int m = (l + r) >> 1;
      if (a[m] <= x) l = m;
      else r = m;
    }
    cout << l << '\n';
  }
  return 0;
}             