#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int a, b, c; cin >> a >> b >> c;
  if (a < 0 || b < 0 || c < 0) return cout << "INVALID", 0;
  if (a + b > c && b + c > a && a + c > b) { // tam giac thuong
    if (a == b || b == c || a == c) {
      if (a == b && a == c) return cout << 1, 0;
      return cout << 2, 0;
    }
    if (a*a == b*b + c*c || b*b == a*a + c*c || c*c == a*a + b*b) return cout << 3, 0;
  }
  else cout << "INVALID";
  return 0;
}