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
  int n; cin >> n;
  vector<array<int, 2>> a(n);
  for (int i = 0; i < n; i++) cin >> a[i][0] >> a[i][1];
  sort(all(a), [](array<int, 2> a, array<int, 2> b) {
    return a[1] < b[1];
  });
  vector<int> dp(n, 0);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int len = a[i][1] - a[i][0];
    dp[i] = len;
    for (int j = 0; j < i; j++) {
      if (a[j][1] <= a[i][0]) dp[i] = max(dp[i], dp[j] + len);
    }
    ans = max(ans, dp[i]);
  }
  cout << ans << '\n';
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}

