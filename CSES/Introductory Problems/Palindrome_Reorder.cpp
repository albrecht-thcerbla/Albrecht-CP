#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;

int cnt[26];

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  // freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  // freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  string s; cin >> s;
  for (int i = 0; i < sz(s); i++) ++cnt[s[i] - 'A'];
  int pos = -1, check = 0;
  for (int i = 0; i < 26; i++) {
    if (cnt[i] & 1) pos = i;
    if (cnt[i] & 1) ++check;
    if (check > 1) return cout << "NO SOLUTION" << '\n', 0;
  }
  if (sz(s) % 2 == 0 && check > 1) cout << "NO SOLUTION" << '\n';
  if (sz(s) & 1 && check > 1) cout << "NO SOLUTION" << '\n';
  // left
  string ans;
  for (int i = 0; i < 26; i++) if (cnt[i] > 1) ans += string((cnt[i] >> 1), i + 'A');
  // mid
  string re_ans = ans; reverse(all(re_ans));
  if (pos != -1) ans += (pos + 'A');
  ans += re_ans;
  cout << ans << '\n';
  return 0;
}