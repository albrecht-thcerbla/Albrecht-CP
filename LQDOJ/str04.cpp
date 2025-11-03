#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  string s; getline(cin, s);
  stringstream ss(s);
  string word, ans;
  while (ss >> word) {
    if (!ans.empty()) ans += " ";
    ans += word;
  }
  cout << ans << '\n';
  return 0;
}