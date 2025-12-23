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
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> cnt(n + 1, 0);
    for (int i = 0; i < n; i++) ++cnt[a[i]];
    bool bad = false;
    vector<int> lim(n + 1, 0);
    for (int i = 1; i <= n; i++) if (cnt[i] % k != 0) bad = true;
    if (bad) {
      cout << 0 << '\n';
      continue;
    }
    for (int i = 1; i <= n; i++) lim[i] = cnt[i] / k;
    vector<int> freq(n + 1, 0);
    int64_t ans = 0;
    int l = 0, r = 0;
    while (r < n) {
      ++freq[a[r]];
      while (freq[a[r]] > lim[a[r]]) --freq[a[l]], ++l;
      ans += (r - l + 1);
      ++r;
    }
    cout << ans << '\n';
  }
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}
