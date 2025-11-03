#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  string s; cin >> s;
  for (int i = 1; i < sz(s); i++) {
    if (abs((s[i] ^ '0') - (s[i - 1] ^ '0')) > 1) return cout << "NO", 0;
  }
  cout << "YES";
  return 0;
}