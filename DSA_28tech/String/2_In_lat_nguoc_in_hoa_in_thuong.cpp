#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  string s; cin >> s;
  for (int i = sz(s) - 1; ~i; i--) cout << s[i];
  cout << '\n';
  for (int i = 0; i < sz(s); i++) {
    char c = tolower(s[i]);
    cout << c;
  }
  cout << '\n';
  for (int i = 0; i < sz(s); i++) {
    char c = toupper(s[i]);
    cout << c;
  }
  cout << '\n';
  return 0;
}