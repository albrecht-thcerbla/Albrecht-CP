#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int n, a[100005], ans = 1;
vector<int> dp(100005, 0);

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  dp[1] = a[1];
  for (int i = 2; i <= n; i++) {
    if (a[i] < dp[1]) dp[1] = a[i];
    else if (a[i] > dp[ans]) dp[++ans] = a[i];
    else {
      int l = 0, r = ans + 1;
      while (r - l > 1) {
        int m = (l + r) >> 1;
        if (dp[m] >= a[i]) r = m;
        else l = m;
      }
      dp[r] = a[i];
    }
  }
  cout << ans << '\n';
  return 0;
}