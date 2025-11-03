#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  string s, t; cin >> s >> t;
  int dt[256] = {0}, cntT = 0;
  for (int i = 0; i < sz(t); i++) {
    ++dt[t[i]];
    if (dt[t[i]] == 1) ++cntT;
  }
  int l = 0, r = 0, ds[256] = {0}, cntS = 0;
  int res = 1e9;
  int st = 0, fn = 0;
  while (r < sz(s)) {
    ds[s[r]]++;    
    if (dt[s[r]] && ds[s[r]] == dt[s[r]]) ++cntS;
    if (cntS == cntT) {
      while (ds[s[l]] - 1 >= dt[s[l]]) {
        --ds[s[l]];
        ++l;
      }
      if (r - l + 1 < res) {
        res = r - l + 1;
        st = l;
        fn = r - l + 1;
      }
    }
    ++r;
  }
  for (int i = st; i < fn + st; i++) cout << s[i];  
  return 0;
}