#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, k; cin >> n >> k;
  int a[n + 1];
  int cnt_one = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt_one += a[i];
  }
  int cnt_zero = 0;
  if (cnt_one < k) return cout << -1, 0;
  for (int i = 1; i <= k; i++) {
    if (a[i] == 0) ++cnt_zero;
    else --cnt_zero;
  }
  int res = cnt_zero;
  for (int i = k + 1; i <= n; i++) {
    if (a[i] == 0) ++cnt_zero;
    if (a[i - k] == 0) --cnt_zero;
    res = min(res, cnt_zero);
  }
  cout << res << '\n';
  return 0;
}