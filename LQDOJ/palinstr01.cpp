#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

bool check(string s) {
  int cnt = 0;
  int l = 0, r = sz(s) - 1;
  while (l < r) {
    cnt += (s[l] != s[r]);
    ++l; --r;
  }
  return cnt <= 2;
}
int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  for (string s; cin >> s; cout << (check(s) ? "YES" : "NO") << '\n');
  return 0;
}