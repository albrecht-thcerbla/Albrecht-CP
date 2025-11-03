#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

long long h[200002], dp[200002];
int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, k; cin >> n >> k;

  for (int i = 1; i <= n; i++) cin >> h[i], dp[i] = 1000000000000;
  dp[1] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= min(i + k, n); j++) {
      dp[j] = min(dp[j], dp[i] + abs(h[i] - h[j]));
    }
  }
  cout << dp[n];
  return 0;
}