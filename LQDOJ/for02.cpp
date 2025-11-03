#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

#define int long long

signed main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  int sum = n * (n + 1) >> 1;
  if (n & 1) n = (n - 1) >> 1;
  else n >>= 1;
  int ans = sum - 2 * (n * (n + 1) >> 1);
  cout << ans;
}