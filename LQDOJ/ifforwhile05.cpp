#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  double s1, t1, s2, t2; cin >> s1 >> t1 >> s2 >> t2;
  double f = s1 / t1;
  double s = s2 / t2;
  if (f > s) cout << "YES" << '\n';
  else cout << "NO" << '\n';
  return 0;
}