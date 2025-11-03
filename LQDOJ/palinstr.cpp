#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  string s; cin >> s;
  int i = 0, j = sz(s) - 1;
  while (i < j) {
    if (s[i] == s[j]) ++i, --j;
    else return cout << "NO", 0;
  }
  cout << "YES";
  return 0;
}