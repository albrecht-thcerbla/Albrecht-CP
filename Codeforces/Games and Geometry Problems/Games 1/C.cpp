#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
const int64_t inf = 1e18;

bool calc(int n, int x, int y) {
  if (!x) return (y == n - 1);
  if (x == n - 1) return (y != 0);
  return x > y;
}
int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cin.exceptions(cin.failbit);
  int tt; cin >> tt;
  while (tt--) {
    int n; cin >> n;
    string s; cin >> s;
    bool ok = false;
    for (int i = 0; i < n; i++) {
      if (s[i] != 'A') continue;
      bool good = true;
      for (int j = 0; j < n; j++) {
        if (s[j] == 'B' && calc(n, j, i)) {
          good = false;
          break;
        }
      }
      if (good) {
        ok = true;
        break;
      }
    }
    if (ok) cout << "Alice" << '\n';
    else cout << "Bob" << '\n';
  }
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}

