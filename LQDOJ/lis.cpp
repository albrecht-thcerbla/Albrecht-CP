#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
const int64_t inf = 1e18;

vector<int> dp(300003, 0);

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cin.exceptions(cin.failbit);
  freopen("/home/albrecht/input.inp", "r", stdin);
  freopen("/home/albrecht/output.out", "w", stdout);
  int n; cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  int ans = 1;
  dp[1] = a[1];
  for (int i = 2; i <= n; i++) {
    if (a[i] < dp[1]) dp[1] = a[i];
    else if (a[i] > dp[ans]) dp[++ans] = a[i];
    else {
      int l = 0, r = ans + 1;
      while (r - l > 1) {
        int m = (l + r) >> 1;
        if (a[i] <= dp[m]) r = m;
        else l = m;
      }
      dp[r] = a[i];
    }
  }
  cout << ans << '\n';
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}