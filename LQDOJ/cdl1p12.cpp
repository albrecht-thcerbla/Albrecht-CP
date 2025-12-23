#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  double a, b; cin >> a >> b;
  double c = sqrt(a * a + b * b);
  double area = a * b / 2;
  cout << fixed << setprecision(2);
  cout << area << '\n' << c << '\n';
  return 0;
}