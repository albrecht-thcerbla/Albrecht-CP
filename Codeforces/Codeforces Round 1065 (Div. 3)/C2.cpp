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
  int tt; cin >> tt;
  while (tt--) {
    int n; cin >> n;
    vector<int> a(n), b(n);
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) cin >> a[i], x ^= a[i];
    for (int i = 0; i < n; i++) cin >> b[i], y ^= b[i];
    int tmp = x ^ y;
    if (tmp == 0) {
      cout << "Tie" << '\n';
      continue;
    }
    int h = 31 - __builtin_clz(tmp);
    int mask = 1 << h;
    int res = -1;
    for (int i = 0; i < n; i++) {
      if ((a[i] ^ b[i]) & mask) res = i;
    }
    if ((res + 1) & 1) cout << "Ajisai" << '\n';
    else cout << "Mai" << '\n';
  }
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}

