/// https://luyencode.net/problem/mk119snt
/// Kien thuc: Sang Eratosthenes, Prefix sum.
#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;

bool p[1000001];
int pref[1000001];
void sieve() {
  for (int i = 0; i <= 1000000; i++) p[i] = true;
  p[0] = p[1] = false;
  for (int i = 2; i * i <= 1000000; i++) {
    if (p[i]) {
      for (int j = 2 * i; j <= 1000000; j += i) {
        p[j] = false;
      }
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  int tt; cin >> tt;
  sieve();
  for (int i = 1; i <= 1000000; i++) pref[i] = pref[i - 1] + p[i];
  while (tt--) {
    int l, r; cin >> l >> r;
    cout << pref[r] - pref[l - 1] << '\n';
  }
  return 0;
}