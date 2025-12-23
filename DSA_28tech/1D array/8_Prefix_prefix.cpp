#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, m, k; cin >> n >> m >> k;
  int a[n + 1], l[n + 1], r[n + 1], d[n + 1], pref[n + 1] = {0}, diff[n + 1] = {0};
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= m; i++) {
    int ll, rr, dd; cin >> ll >> rr >> dd;
    l[i] = ll; r[i] = rr; d[i] = dd;
  }
  diff[1] = a[1];
  for (int i = 2; i <= n; i++) diff[i] = a[i] - a[i - 1];
  for (int i = 1; i <= k; i++) {
    int x, y; cin >> x >> y;
    for (int j = x; j <= y; j++) {
      diff[l[j]] += d[j]; diff[r[j] + 1] -= d[j];  
    }
  }
  pref[1] = diff[1];
  for (int i = 2; i <= n; i++) {
    pref[i] += pref[i - 1] + diff[i];
  }
  for (int i = 1; i <= n; i++) cout << pref[i] << " ";
  return 0;
}