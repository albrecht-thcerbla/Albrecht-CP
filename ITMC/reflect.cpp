#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
const int64_t inf = 1e18;
const long double pi = acos(-1);
const long double eps = 1e-12;

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  int tt; cin >> tt;
  while (tt--) {
    long double l, d, x, theta; cin >> l >> d >> x >> theta;
    long double d90 = fabsl(theta - 90.0);
    if (d90 <= eps) {
      cout << 0 << '\n';
      continue;
    }
    long double alpha = fabsl(90.0 - theta);
    long double rad = alpha * pi / 180.0;
    long double tana = tanl(rad);
    if (fabsl(tana) <= eps) {
      cout << 0 << '\n';
      continue;
    }
    long double fi = (theta < 90.0) ? x / tana : (d - x) / tana;
    if (fi + eps >= l)  {
      cout << 0 << '\n';
      continue;
    }
    long double cycle = d / tana;
    long double val = (l - fi + eps) / cycle;
    int64_t more = (int64_t) floorl(val), cnt = more + 1;
    cout << cnt << '\n';
  }
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}
