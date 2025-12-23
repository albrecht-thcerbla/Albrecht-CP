#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  string s; cin >> s;
  int cnt = 0;
  int mx = -1;
  int r;
  for (int i = 1; i < sz(s); i++) {
    if (s[i] == s[i - 1]) {
      ++cnt;
    }
    else cnt = 0;
    if (cnt > mx) {
      mx = cnt;
      r = i;
    }
  }
  cout << mx + 1 << '\n';
  for (int i = r - mx; i <= r; i++) cout << s[i];
  return 0;
}