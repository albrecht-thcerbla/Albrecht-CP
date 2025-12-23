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
  string s; cin >> s;
  int cnt2 = 0;
  for (int i = 0; i < sz(s); i++) if (s[i] == '2') ++cnt2;
   bool ok = (s[0] == s[sz(s) - 1]);
  cout << s << '\n';
  cout << cnt2 << '\n';
  cout << (ok ? "YES" : "NO") << '\n';
  reverse(all(s));
  cout << s << '\n';
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}

