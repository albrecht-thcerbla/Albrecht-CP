#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int n, k;
string s, res;
void backtrack(int i, string str, int cnt) {
  if (cnt > k || i > n) return;
  res = max(res, str);
  char mx = str[i];
  for (int j = i + 1; j <= n; j++) mx = max(mx, str[j]);
  if (mx == str[i]) {
    backtrack(i + 1, str, cnt);
  } else {
    for (int j = i + 1; j <= n; j++) {
      if (str[j] == mx) {
        string tmp = str;
        swap(tmp[i], tmp[j]);    
        backtrack(i + 1, tmp, cnt + 1);
      }
    }
  }
}
int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> k >> s;
  n = sz(s);
  s = " " + s;
  res = s;
  backtrack(1, s, 0);
  cout << res.substr(1) << '\n';
  return 0;
}