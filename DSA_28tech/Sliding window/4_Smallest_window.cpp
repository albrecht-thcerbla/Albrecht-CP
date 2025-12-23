#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  string s; cin >> s;
  int ds[256] = {0}, cntS = 0;
  int l = 0, r = 0;  
  for (int i = 0; i < sz(s); i++) {
    ++ds[s[i]];
    if (ds[s[i]] == 1) {
      ++cntS;
      r = i;
    }
  }
  int res = 1e9;
  while (r < sz(s)) {
    while (ds[s[l]] - 1 > 0) {
      ds[s[l]]--;
      ++l;
    }
    res = min(res, r - l + 1);
    ++r;
  }
  cout << res << '\n';
  return 0;
}