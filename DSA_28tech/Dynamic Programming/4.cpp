#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
const int64_t inf = 1e18;

// Day con co tong bang S
// Goi dp[i][j]: xet den phan tu thu i ma tao duoc tong la j

int dp[202][500005];

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cin.exceptions(cin.failbit);
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  int n, s; cin >> n >> s;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 0; i <= n; i++) dp[i][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= s; j++) {
      if (j >= a[i]) dp[i][j] = dp[i - 1][j] || dp[i - 1][j - a[i]];
      else dp[i][j] = dp[i - 1][j];
    }
  }
  cout << dp[n][s] << '\n';
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}