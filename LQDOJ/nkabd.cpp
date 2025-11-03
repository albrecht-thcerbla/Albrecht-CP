#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;

int p[1000001], pref[1000001], a[1000001], l, r;

void sieve() {
  for (int i = 2; i <= 1000000; i++) {
    for (int j = 2; i * j <= 1000000; j++) {
      p[i * j] += j;
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> l >> r;
  sieve();
  int cnt = 0;
  for (int i = l; i <= r; i++) {
    if (p[i] > i) ++cnt;
  }
  cout << cnt << '\n';
  return 0;
}