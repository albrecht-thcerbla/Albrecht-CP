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
    int n, s, k; cin >> n >> s >> k;
    set<int> se;
    for (int i = 0; i < k; i++) {
      int x; cin >> x;
      se.insert(x);
    }
    int ans = -1;
    for (int i = 0; i <= k; i++) {
      int down = s - i;
      if (down >= 1 && !se.count(down)) {
        ans = i;
        break;
      }
      int up = s + i;
      if (up <= n && !se.count(up)) {
        ans = i;
        break;
      }
    }
    cout << ans << '\n';
  }
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}
