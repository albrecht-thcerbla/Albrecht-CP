#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  long long n, x, q; cin >> n >> x >> q;
  long long a[n + 1], pref[n + 1] = {0};
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pref[i] = pref[i - 1] + a[i];
  }
  long long cnt = 0;
  while (q--) {
    int u, v; cin >> u >> v;
    long long sum = pref[v] - pref[u - 1];
    if (sum < x) ++cnt;
  }
  cout << cnt;
  return 0;
}