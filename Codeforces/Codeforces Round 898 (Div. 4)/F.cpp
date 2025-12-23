#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
const int64_t inf = 1e18;

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cin.exceptions(cin.failbit);
  int tt; cin >> tt;
  while (tt--) {
    int n, k; cin >> n >> k;
    vector<int> a(n), h(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> h[i];
    int l = 0, ans = 0;
    int64_t sum = 0;
    for (int r = 0; r < n; r++) {
      if (r && h[r - 1] % h[r] != 0) l = r, sum = 0;
      sum += a[r];
      while (l <= r && sum > k) sum -= a[l++];
      if (sum <= k) ans = max(ans, r - l + 1);
    }
    cout << ans << '\n';
  }
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}

