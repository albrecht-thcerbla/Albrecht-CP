#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
const int64_t inf = 1e18;

int euclid(int n, int m, int h = 0) {
  int res = 0;
  while (n && m) {
    if (n < m) swap(n, m);
    res += n / m;
    n %= m;
  }
  return res;
}
int calc(int n, int m) {
  if (n == m) return 1;
  int ans = euclid(n, m);
  for (int i = 1; i <= n / 2; i++) ans = min(ans, euclid(i, m) + euclid(n - i, m));
  for (int j = 1; j <= m / 2; j++) ans = min(ans, euclid(n, j) + euclid(n, m - j));
  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cin.exceptions(cin.failbit);
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  int n, m; cin >> n >> m;
  cout << calc(n, m) << '\n';
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}