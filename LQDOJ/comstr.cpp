#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  string s; cin >> s;
  vector<char> ch;
  vector<int> cnt;
  ch.emplace_back(s[0]);
  for (int i = 1; i < sz(s); i++) if (s[i] != s[i - 1]) ch.emplace_back(s[i]);
  int res = 1;
  for (int i = 1; i < sz(s); i++) {
    if (s[i] == s[i - 1]) ++res;
    else {
      cnt.emplace_back(res);
      res = 1;
    }
  }
  cnt.emplace_back(res);                                        
  for (int i = 0; i < sz(ch); i++) {
    if (cnt[i] > 1) cout << cnt[i] << ch[i];
    else cout << ch[i];
  }
  return 0;
}