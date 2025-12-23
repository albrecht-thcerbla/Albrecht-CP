#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

void pl(string a, string b) {
  if (sz(a) < sz(b)) swap(a, b);
  while (sz(a) != sz(b)) b = '0' + b;
  string sum = a;
  int carry = 0, s1 = 0;
  for (int i = sz(a) - 1; ~i; i--) {
    s1 = (a[i] ^ '0') + (b[i] ^ '0') + carry;
    sum[i] = (s1 % 10) + '0';
    carry = s1 / 10;
  }
  if (carry) sum = '1' + sum;
  cout << sum;
}
int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  string a, b; cin >> a >> b;
  pl(a, b);
  return 0;
}