#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  long long a[n + 1];
  for (int i = 1; i <= n; i++) cin >> a[i];
  long long mx = -1e9;
  for (int i = 1; i <= n; i++) {
    long long sq = sqrt(a[i]);
    if (sq * sq == a[i]) continue;
    mx = max(mx, a[i]);
  }
  cout << mx << '\n';
  return 0;
}