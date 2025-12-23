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
    map<int, int> mp;
    for (int i = 0; i < (n << 1); i++) {
      int x; cin >> x;
      ++mp[x];
    }
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    for (auto [v, c] : mp) {
      if (c & 1) ++cnt1;
      else if (c % 4 == 0) ++cnt0;
      else ++cnt2;
    }
    int ans = cnt1 + (cnt0 << 1) + (cnt2 << 1);
    if (!cnt1 && cnt0 & 1) ans -= 2;
    cout << ans << '\n';
  }
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}

