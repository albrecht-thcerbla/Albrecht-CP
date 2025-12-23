#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
#define int int64_t

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
const int64_t inf = 1e18;

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  int n; cin >> n;
  vector<int> a;
  int l = 1, r = n * n, ans = -1;
  int half = (n * n + 1) >> 1;
  while (l <= r) {
    int m = (l + r) >> 1;
    int cnt = 0;
    for (int i = 1; i <= n; i++) cnt += min(n, m / i);
    if (cnt >= half) {
      ans = m;
      r = m - 1;
    } else l = m + 1;
  }
  cout << ans << '\n';
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}