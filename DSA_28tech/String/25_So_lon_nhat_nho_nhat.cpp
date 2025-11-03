#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int m, s; cin >> m >> s;
  if (9 * m < s || s == 0 && m > 1) return cout << "NOT FOUND" << '\n', 0;
  string ss = string(m, '0');
  int sum = 0, tmp = s;
  for (int i = 0; i < m; i++) {
    if (tmp > 9) {
      sum += 9;
      tmp -= 9;
      ss[i] = '9';
    } else {
      sum += tmp;
      ss[i] = tmp + '0';
    }
  }
  cout << ss << '\n';
  reverse(all(ss));
  string sss = ss;
  while (sss[0] == 0) {
    sss.erase(0, 1);
  }
  cout << sss << '\n';
  return 0;
}