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
  struct Job {
    int64_t start, finish, profit;
  };
  int n; cin >> n;
  vector<Job> a(n + 1);
  vector<int64_t> dp(n + 1, 0);
  for (int i = 1; i <= n; i++) cin >> a[i].start >> a[i].finish >> a[i].profit;
  sort(a.begin() + 1, a.end(), [](Job a, Job b) {
    return a.finish < b.finish;
  });
  auto fipos = [&](int i, int x) {
    int l = 0, r = i;
    while (r - l > 1) {
      int m = (l + r) >> 1;
      if (a[m].finish <= x) l = m;
      else r = m;
    }
    return l;
  };
  for (int i = 1; i <= n; i++) {
    if (fipos(i, a[i].start - 1) == -1) dp[i] = max(a[i].profit, dp[i - 1]);
    else dp[i] = max(dp[i - 1], a[i].profit + dp[fipos(i, a[i].start - 1)]);
  }
  cout << dp[n] << '\n';
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}
