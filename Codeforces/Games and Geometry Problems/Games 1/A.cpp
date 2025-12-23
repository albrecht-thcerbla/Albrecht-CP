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
    for (int i = 0; i < sz(s); i++) {
      if (i & 1) {
        if (s[i] == 'z') s[i] = 'y';
        else s[i] = 'z';
      } else {
        if (s[i] == 'a') s[i] = 'b';
        else s[i] = 'a';
      }
    }
    cout << s << '\n';
  }
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}

