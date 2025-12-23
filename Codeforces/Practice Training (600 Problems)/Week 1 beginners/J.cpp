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
  int tt; cin >> tt;
  while (tt--) {
    int r, g, b, w; cin >> r >> g >> b >> w;
    int odd = (r % 2) + (g % 2) + (b % 2) + (w % 2);
    if (odd <= 1) cout << "YES" << '\n';
    else if (r && g && b) {
      --r; --g; --b;
      w += 3;
      odd = (r % 2) + (g % 2) + (b % 2) + (w % 2);
      if (odd <= 1) cout << "YES" << '\n';
      else cout << "NO" << '\n';
    } else cout << "NO" << '\n';
  }
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}