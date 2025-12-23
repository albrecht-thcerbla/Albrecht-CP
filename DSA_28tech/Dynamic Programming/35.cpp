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
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  int n; cin >> n;
  vector<int> a(n + 1), dp(n + 1, 0);
  map<int, int> mp;
  mp[0] = 1;
  int odd = 0, cnt = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    dp[i] = (odd += (a[i] & 1 ? 1 : -1));
    cnt += mp[dp[i]]++;
  }
  cout << cnt << '\n';
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}