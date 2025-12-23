#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, k; cin >> n >> k;
  int a[n + 1];
  for (int i = 1; i <= n; i++) cin >> a[i];
  map<int, int> mp;
  mp[0] = 0;
  int sum = 0;
  int res = -1;
  for (int i = 1; i <= n; i++) {
    (sum += a[i] % k + k) %= k;
    if (mp.count(sum)) res = max(res, i - mp[sum]);
    if (mp.count(sum) == 0) mp[sum] = i;
  }
  cout << res << '\n';
  return 0;
}