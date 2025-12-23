#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, m; cin >> n >> m;
  int a[n + 1], b[m + 1];
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= m; i++) cin >> b[i];
  int i = 1, j = 1;
  while (i <= n && j <= m) {
    if (a[i] == b[j]) {
      ++j;
    }
    ++i;
  }
//  cout << i << " " << j << '\n';
  if (j == m + 1) cout << "YES" << '\n';
  else cout << "NO" << '\n';
  return 0;
}