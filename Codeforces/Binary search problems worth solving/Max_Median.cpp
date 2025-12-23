// https://codeforces.com/contest/1486/problem/D
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
  int n, k; cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  int l = 1, r = n + 1;
  while (r - l > 1) {
    int m = (l + r) >> 1;
    vector<int> pref(n + 1, 0);
    for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + (a[i - 1] >= m ? 1 : -1);
    int minpref = 0, ok = 0;
    for (int i = k; i <= n; i++) {
      minpref = min(minpref, pref[i - k]);
      if (pref[i] - minpref > 0) {
        ok = 1;
        break;
      }
    }
    if (ok) l = m;
    else r = m;
  }
  cout << l << '\n';
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}

