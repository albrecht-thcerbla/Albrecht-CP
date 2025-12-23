#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int cnt[256];
int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  string s; cin >> s;
  for (int i = 0; i < sz(s); i++) {
    ++cnt[s[i] ^ '0'];
  }
  int res = 0;
  for (int i = 0; i < 256; i++) {
    if (cnt[i] == 1) {
      ++res;
    }
  }
  cout << res;
  return 0;
}