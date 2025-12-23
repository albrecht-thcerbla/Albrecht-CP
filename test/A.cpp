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
//  freopen("/home/albrecht/input.inp", "r", stdin);
//  freopen("/home/albrecht/output.out", "w", stdout);
  int tt; cin >> tt; 
  while (tt--) {
    int n; cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
      int x; cin >> x;
      mp[x]++;
    }
    int k = (n - 1) / 2;
    int need = (n % 2 == 0) ? 2 : 1;
    vector<int> pval, sval;
    for (auto [n, f] : mp) {
      for (int i = 0; i < f / 2; i++) pval.emplace_back(n);
      if (f % 2 == 1) sval.emplace_back(n);
    }
    if (sz(pval) < k) {
      cout << "NO" << '\n';
      continue;
    }
    sort(all(pval));
    vector<int> c;
    for (int i = 0; i < k; i++) c.emplace_back(pval[i]);
    for (int i = k; i < sz(pval); i++) {
      sval.emplace_back(pval[i]);
      sval.emplace_back(pval[i]);
    }
    sort(all(sval));
    if (sz(sval) != need) {
      cout << "NO" << '\n';
      continue;
    }
    if (k == 0) {
      cout << "YES" << '\n';
      continue;
    }
    bool ok = true;
    if (need == 1) if (sval[0] > c[0]) ok = false;
    else {
      if (sval[0] > c[0] || c.back() > sval[1]) ok = false;
    }
    if (ok) cout << "YES" << '\n';
    else cout << "NO" << '\n';
  }
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}
