#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  string s; cin >> s;
  int cnt = 1, mx = 1;
  for (int i = 1; i < sz(s); i++) {
    if (s[i] == s[i - 1]) ++cnt;
    else cnt = 1;
    mx = max(mx, cnt);
  }
  cout << mx << '\n';
  return 0;
}