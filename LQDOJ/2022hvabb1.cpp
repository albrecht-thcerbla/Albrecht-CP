#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("tongchuso.inp", "r", stdin);
  freopen("tongchuso.out", "w", stdout);
  string s; cin >> s;
  int sum = 0;
  for (int i = 0; i < sz(s); i++) sum += (s[i] ^ '0');
  cout << sum;
  return 0;
}