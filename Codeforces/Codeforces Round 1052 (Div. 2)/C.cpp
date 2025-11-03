#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  int tt; cin >> tt;
  while (tt--) {
    int n; cin >> n;
    string s; cin >> s;
    s = '1' + s + '1';
    bool ok = false;
    vector<int> ans(n + 1);
    for (int i = 1; i <= n; i++) ans[i] = i;
    for (int i = 1; i <= sz(s); i++) {
      if (s[i] == '0') {
        if (s[i - 1] == '1' && s[i + 1] == '1') {
          ok = true;
          break;
        } else if (s[i - 1] == '0') swap(ans[i - 1], ans[i]);
      }
    }
    if (ok) {
      cout << "NO" << '\n';
      continue;
    }
    cout << "YES" << '\n';
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << '\n';
  }
  return 0;
}