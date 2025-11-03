#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int cnt[10];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  string s; cin >> s;
  bool ok = false;
  int sum = 0;
  for (int i = 0; i < sz(s); i++) {
    ++cnt[s[i] ^ '0'];
    if (s[i] == '0') ok = true;
    sum += (s[i] ^ '0');
  }
  if (sum % 3 != 0 || !ok) return cout << -1, 0;
  string ans;
  if (sz(s) == 1) return cout << -1, 0;
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < cnt[i]; j++) {
      ans += (i + '0');
    }
  }
  reverse(all(ans));
  if (ans == s) cout << -1;
  cout << ans;
  return 0;
}