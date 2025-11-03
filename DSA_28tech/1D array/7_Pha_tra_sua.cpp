#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, k, q; cin >> n >> k >> q;
  int a[200002] = {0};
  // thao tac
  for (int i = 1; i <= n; i++) {
    int l, r; cin >> l >> r;
    a[l]++; a[r + 1]--;
  }
  // truy van
  for (int i = 2; i <= 200000; i++) a[i] += a[i - 1];
  int ans[200002] = {0};
  for (int i = 1; i <= 200000; i++) {
    if (a[i] >= k) ++ans[i];    
    ans[i] += ans[i - 1];
  }
  for (int i = 1; i <= q; i++) {
    int l, r; cin >> l >> r;
    cout << ans[r] - ans[l - 1] << '\n';
  }
  return 0;
}