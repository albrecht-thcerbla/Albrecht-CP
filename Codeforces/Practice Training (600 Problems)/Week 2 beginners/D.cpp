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
    string p, h; cin >> p >> h;
    int n = sz(p), m = sz(h);
    if (n > m) {
      cout << "NO" << '\n';
      continue;
    }
    vector<int> cntp(26, 0);
    for (char c : p) ++cntp[c - 'a'];
    vector<int> cnth(26, 0);
    for (int i = 0; i < n; i++) ++cnth[h[i] - 'a'];
    bool ok = false;
    if (cntp == cnth) ok = true;
    for (int i = n; i < m && !ok; i++) {
      cnth[h[i - n] - 'a']--;
      cnth[h[i] - 'a']++;
      if (cnth == cntp) ok = true;
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}


