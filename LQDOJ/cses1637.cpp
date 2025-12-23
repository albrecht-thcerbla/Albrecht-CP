#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int mx(int x) {
  string str = to_string(x);
  int mx1 = 0;
  for (int i = 0; i < sz(str); i++) mx1 = max(mx1, str[i] ^ '0');
  return mx1;
}
int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  int cnt = 0;
  while (n) {
    n -= mx(n);
    ++cnt;
  }
  cout << cnt;
  return 0;
}