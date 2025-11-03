#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  string s; cin >> s;
  int cnt = 0;
  for (int i = 0; i < sz(s); i++) {
    if ((s[i] ^ '0') & 1) ++cnt;
  }
  cout << cnt;
  return 0;
}