#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  vector<int64_t> a(n);
  int64_t sum = 0;
  for (int i = 0; i < n; i++) cin >> a[i], sum += a[i];
  int64_t ans = LLONG_MAX;
  for (int mask = 0; mask < (1 << n); mask++) {
    int64_t res = 0;
    for (int i = 0; i < n; i++) {
      if (mask & (1 << i)) res += a[i];
    }
    ans = min(ans, abs(2 * res - sum));
  }
  cout << ans << '\n';
  return 0;
}