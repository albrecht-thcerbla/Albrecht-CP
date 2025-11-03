#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define int int64_t

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;

int binpow(int a, int b) {
  if (!b) return 1;
  int x = binpow(a, b / 2);
  (x *= x) %= mod;
  if (b & 1) x = (x * (a % mod)) % mod;
  return (x);
}
int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  cout << binpow(2, n) << '\n';
  return 0;
}