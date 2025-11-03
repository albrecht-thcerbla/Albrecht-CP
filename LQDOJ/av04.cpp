#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  long double sum = 0;
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    double x; cin >> x;
    if (x < 0) {
      ++cnt;
      sum += x;
    }
  }
  if (!cnt) return cout << -1, 0;
  long double ans = sum / cnt;
  cout << fixed << setprecision(2) << ans;
  return 0;
}