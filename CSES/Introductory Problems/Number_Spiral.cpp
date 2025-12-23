#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define int long long 
const int mod = 1e9 + 7;
// max le thi tang dan
// max chan thi giam dan


signed main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    int x, y; cin >> x >> y;
    int tmp = 0;
    int mx = max(x, y);
    if (mx & 1) {
      if (x < y) tmp += (--mx) * mx + 2 * y - x;
      else tmp += (--mx) * mx + y;
    } else {
      if (x > y) tmp += (--mx) * mx + 2 * x - y;
      else tmp += (--mx) * mx + x;
    }
    cout << tmp << '\n';
  }
  return 0;
}