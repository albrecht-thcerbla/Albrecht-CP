#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int a, b, d1, d2, d3, x; cin >> a >> b >> d1 >> d2 >> d3 >> x;
  long long ans;
  if (x <= a) {
    ans = x * d1;
  } else if (x > a && x <= b) {
    ans = a * d1 + (x - a) * d2;
  } else {
    ans = a * d1 + (b - a) * d2 + (x - b) * d3;
  }
  cout << ans;
  return 0;
}