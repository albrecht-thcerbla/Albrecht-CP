#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int a, b, c; cin >> a >> b >> c;
  cout << (a + b / c - (c % a)) << '\n';
  cout << (-a + b * c) << '\n';
  cout << (a / b / c) << '\n';
  cout << (a % b % c) << '\n';
  return 0;
}