#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;

int cnt[10];

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("MATMA.INP", "r", stdin);
  freopen("MATMA.OUT", "w", stdout);
  string s; cin >> s;
  int sum = 0;
  bool ok = false;
  for (int i = 0; i < sz(s); i++) {
    ++cnt[s[i] - '0'];
    sum += (s[i] - '0');
    if (s[i] == '0') ok = true;
  }
  if (sum % 3 == 0 && ok) {
    for (int i = 9; ~i; --i) {
      if (cnt[i] != 0) {
        for (int j = 0; j < cnt[i]; j++) {
          cout << i;
        }
      }
    }
  } else cout << -1 << '\n';

  return 0;
}