#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
const int64_t inf = 1e18;

int dp[1000001];

int calc(int n) {
  if (!n) return 0;
  if (dp[n] != -1) return dp[n];
  int m = n;
  int res = 1e9;
  while (m) {
    int d = m % 10;
    m /= 10;
    if (d != 0) res = min(res, calc(n - d) + 1);
  }
  return dp[n] = res;
}
int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cin.exceptions(cin.failbit);
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  int n; cin >> n;
  memset(dp, -1, sizeof dp);
  cout << calc(n) << '\n';
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}