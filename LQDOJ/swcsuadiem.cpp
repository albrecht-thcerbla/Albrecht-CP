#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  double sum = 0;
  double mn = 100;
  for (int i = 1; i <= n; i++) {
    double x; cin >> x;
    sum += x;
    mn = min(mn, x);
  }
  sum = sum - mn + 10.0;
  cout << fixed << setprecision(1) << sum;
  return 0;
}