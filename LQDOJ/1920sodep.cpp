#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  string s; cin >> s;
  while (sz(s) != 1) {
    int sum = 0;
    for (int i = 0; i < sz(s); i++) sum += (s[i] ^ '0');
    s = to_string(sum);
  }
  cout << s;
  
  return 0;
}