#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, k; cin >> n >> k;
  int a[n + 1], pref[n + 1] = {0};
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  k = min(k, n - k);
  long long s1 = 0, s2 = 0;
  for (int i = 1; i <= n; i++) {
    if (i <= k) s1 += a[i];
    else s2 += a[i];
  }
  cout << abs(s1 - s2) << '\n';
  return 0;
}