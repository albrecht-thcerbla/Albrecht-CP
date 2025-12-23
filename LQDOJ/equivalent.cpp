#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  string a, b; cin >> a >> b;
  map<char, int> mp;
  for (int i = 0; i < sz(a); i++) ++mp[a[i]];
  int cnt = 0;
  for (int i = 0; i < sz(b); i++) {
    if (mp[b[i]]) {
      ++cnt;
      mp[b[i]]--;
    }
  }
  cout << cnt;
  return 0;
}