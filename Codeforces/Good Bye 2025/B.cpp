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
    string s; cin >> s;
    int cnt = 0;
    if (s[0] == 'u') s[0] = 's', ++cnt;
    if (s[sz(s) - 1] == 'u') s[sz(s) - 1] = 's', ++cnt;
    for (int i = 0; i < sz(s) - 1; i++) {
      if (s[i] == 'u' && s[i + 1] == 'u') s[i + 1] = 's', ++cnt;
    }
    cout << cnt << '\n';
  }
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}

