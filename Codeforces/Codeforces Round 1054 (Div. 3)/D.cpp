#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;

int64_t solve(string s, char c) {
  vector<int> pos;
  for (int i = 0; i < sz(s); i++) if (s[i] == c) pos.emplace_back(i);
  int m = sz(pos);
  if (!m) return 0;
  vector<int64_t> v(m), pref(m + 1, 0);
  for (int i = 0; i < m; i++) v[i] = pos[i] - i;
  sort(all(v));
  for (int i = 0; i < m; i++) pref[i + 1] = pref[i] + v[i];
  int64_t res = 1e18;
  for (int i = 0; i < m; i++) {
    int64_t l = int64_t(i) * v[i] - pref[i];
    int64_t r = (pref[m] - pref[i + 1]) - int64_t(m - i - 1) * v[i];
    res = min(res, l + r);
  }
  return res;
}
int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  int tt; cin >> tt;
  while (tt--) {
    int n; cin >> n;
    string s; cin >> s;
    int64_t ans = min(solve(s, 'a'), solve(s, 'b'));
    cout << ans << '\n';
  }
  return 0;
}