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
  freopen("/home/albrecht/input.inp", "r", stdin);
  freopen("/home/albrecht/output.out", "w", stdout);
  int tt; cin >> tt;
  while (tt--) {
    string s; cin >> s;
    int n = sz(s);
    bool ok = false;
    for (int i = 0; i + 1 < n; ++i) {
      bool lhasr = (s[i] == '>' || s[i] == '*');
      bool rhasl = (s[i+1] == '<' || s[i+1] == '*');
      if (lhasr && rhasl) {
        ok = true;
        break;
      }
    }
    if (ok) {
      cout << -1 << '\n';
      continue;
    }
    vector<int> times(n, -1);
    vector<char> in_st(n, 0);
    for (int i = 0; i < n; ++i) {
      if (times[i] != -1) continue;
      vector<pair<int,int>> st;
      st.emplace_back(i, 0);
      while (sz(st)) {
        auto [u, state] = st.back(); st.pop_back();
        if (!state) {
          if (times[u] != -1) continue;
          if (in_st[u]) {
            ok = true;
            break;
          }
          in_st[u] = 1;
          st.emplace_back(u, 1);
          if (s[u] == '<') {
            if (u - 1 >= 0 && times[u - 1] == -1) st.emplace_back(u - 1, 0);
          } else if (s[u] == '>') {
            if (u + 1 < n && times[u + 1] == -1) st.emplace_back(u + 1, 0);
          } else { // '*'
            if (u - 1 >= 0 && times[u-1] == -1) st.emplace_back(u - 1, 0);
            if (u + 1 < n && times[u+1] == -1) st.emplace_back(u + 1, 0);
          }
        } else {
          if (s[u] == '<') {
            int t = (u - 1 >= 0 ? times[u - 1] : 0);
            times[u] = 1 + t;
          } else if (s[u] == '>') {
            int t = (u + 1 < n ? times[u + 1] : 0);
            times[u] = 1 + t;
          } else {
            int t1 = (u - 1 >= 0 ? times[u - 1] : 0);
            int t2 = (u + 1 < n ? times[u + 1] : 0);
            times[u] = 1 + max(t1, t2);
          }
          in_st[u] = 0;
        }
      }
      if (ok) break;
    }
    if (ok) {
      cout << -1 << '\n';
      continue;
    }
    int ans = 0;
    for (int i = 0; i < sz(times); i++) ans = max(ans, times[i]);
    cout << ans << '\n';
  }
  return 0;
}
