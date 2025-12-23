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
    vector<int> p(n + 5), pos(n + 5);
    for (int i = 1; i <= n; i++) cin >> p[i], pos[p[i]] = i;
    vector<int> pref(n + 5, INT_MAX), suff(n + 5, INT_MIN);
    for (int i = 1; i <= n; i++) pref[i] = min(pref[i - 1], pos[i]);
    for (int i = n; i >= 1; i--) suff[i] = max(suff[i + 1], pos[i]);
    bool ok = true;
    for (int i = 1; i <= n - 1; i++) {
      if (pref[i] > suff[i + 1]) {
        ok = false;
        break;
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}

