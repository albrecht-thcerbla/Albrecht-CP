#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
const int64_t inf = 1e18;
const int64_t nmax = 1e12;

int x;
int64_t y, k;

int64_t calc(int64_t v) {
  int64_t cur = v;
  for (int i = 0; i < x; i++) {
    if (!cur) break;
    cur -= cur / y;
  }
  return cur;
}
int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cin.exceptions(cin.failbit);
  freopen("/home/albrecht/input.inp", "r", stdin);
  freopen("/home/albrecht/output.out", "w", stdout);
  int tt; cin >> tt;
  while (tt--) {
    cin >> x >> y >> k;
    if (calc(nmax) < k) {
      cout << -1 << '\n';
      continue;
    }
    int64_t l = 0, r = nmax + 1;
    while (r - l > 1) {
      int64_t m = l + (r - l) / 2;
      if (calc(m) >= k) r = m;
      else l = m;
    }
    cout << r << '\n';
  }
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}