#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;

int phi(int n) {
  if (n == 1) return 1;
  int res = n;
  for (int p = 2; p * p <= n; p++) {
    if (n % p == 0) {
      while (n % p == 0) n /= p;
      res -= res / p;
    }
  }
  if (n > 1) res -= res / n;
  return res;
}
int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  int tt; cin >> tt;
  while (tt--) {
    int n; cin >> n;
    cout << phi(n) << '\n';
  }
  return 0;
}