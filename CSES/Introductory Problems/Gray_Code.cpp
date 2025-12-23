#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  for (int i = 0; i < (1 << n); i++) {
    int g = i ^ (i >> 1);
    for (int j = n - 1; ~j; --j) {
      cout << (g >> j & 1);
    }
    cout << '\n';
  }
  return 0;
}