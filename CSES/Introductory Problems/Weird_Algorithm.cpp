#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define int long long

const int mod = 1e9 + 7;

signed main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  while (n != 1) {
    cout << n << " ";
    if (n & 1) (n *= 3) += 1;
    else n >>= 1;
  }
  cout << 1;
  return 0;
}