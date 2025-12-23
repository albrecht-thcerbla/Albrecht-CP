#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  double a, b; cin >> a >> b;
  double res = b / a;
  if (res < 0.1) {
    cout << "Arabica mat mua." << '\n';
    cout << "He so gia ban: 3";
  } else if (res >= 0.1) {
    cout << "Arabica duoc mua." << '\n';
    cout << "He so gia ban: 2";
  }
  return 0;
}