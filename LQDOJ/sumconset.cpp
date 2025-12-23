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
  freopen("/home/albrecht/input.inp", "r", stdin);
  freopen("/home/albrecht/output.out", "w", stdout);
  int n, t; cin >> n >> t;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  int64_t sum = 0;
  int l = 0, ans = 0;
  for (int r = 0; r < n; r++) {
    sum += a[r];
    while (l <= r && sum > t) sum -= a[l++];
    ans = max(ans, r - l + 1);
  }
  cout << ans << '\n';
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}