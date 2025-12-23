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
    vector<int> even, odd;
    for (int i = 0; i < n; i++) {
      int x; cin >> x;
      if (x & 1) odd.emplace_back(x);
      else even.emplace_back(x);
    }
    if (!sz(odd)) {
      cout << 0 << '\n';
      continue;
    }
    int64_t ans = 0;
    for (int i = 0; i < sz(even); i++) ans += even[i];
    sort(all(odd), greater<int>());
    for (int i = 0; i < (sz(odd) + 1) / 2; i++) ans += odd[i];
    cout << ans << '\n';
  }
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}
