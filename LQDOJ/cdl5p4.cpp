#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

string a, b;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> a >> b;
  int n = sz(a);
  int m = sz(b);
  int cnt = 0;
  for (int i = 0; i < n - m + 1; i++) {
    string tmp = a.substr(i, m);
    if (tmp == b) {
      ++cnt;
      i = i + m - 1;
    }
  }
  cout << cnt;
  return 0;
}