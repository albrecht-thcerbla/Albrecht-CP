#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  string s; cin >> s;
  int ds[256] = {0};
  int l = 0, r = 0, cntS = 0;
  int new_ds[256] = {0};
  int res = 1;
  while (r < sz(s)) {
    ++new_ds[s[r]];
    while (new_ds[s[r]] > 1) {
      --new_ds[s[l]];
      ++l;
    }
    res = max(res, r - l + 1);
    ++r;
  }
  cout << res << '\n';
  return 0;
}