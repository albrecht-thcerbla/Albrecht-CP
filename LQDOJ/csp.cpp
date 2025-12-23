#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, m; cin >> n >> m;
  int a[n + 1];
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  int l = 0, r = n - 1;
  long long cnt = 0;
  while (l < r) {
    if (a[l] + a[r] <= m) {
      cnt += (r - l);
      ++l;
    } else --r;
  }
  cout << cnt << '\n';
  return 0;
}