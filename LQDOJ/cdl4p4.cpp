// author : albrecht
#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, m; cin >> n >> m;
  string a = to_string(n), b = to_string(m);
  auto add = [&](string a, string b) -> string {
    for (int i = 0; i < max(sz(a), sz(b)); i++) {
      if (sz(a) == sz(b)) break;
      if (sz(a) < sz(b)) a = '0' + a;
      else b = '0' + b;
    }
    int carry = 0, sum;
    string ans = a;
    for (int i = sz(a) - 1; ~i; --i) {
      sum = (a[i] ^ '0') + (b[i] ^ '0') + carry;
      carry = sum / 10;
      ans[i] = (sum % 10) + '0';
    }
    if (carry == 1) ans = '1' + ans;
    return ans;
  };
  auto sub = [&](string a, string b) -> string {
    for (int i = 0; i < max(sz(a), sz(b)); i++) {
      if (sz(a) == sz(b)) break;
      else if (sz(a) < sz(b)) a = '0' + a;
      else b = '0' + b;
    }
    int carry = 0, sum;
    string ans = a;
    for (int i = sz(a) - 1; ~i; --i) {
      sum = (a[i] ^ '0') - (b[i] ^ '0') - carry;
      if (sum < 0) {
        sum += 10;
        carry = 1;
      }
      else carry = 0;
      ans[i] = (sum + '0');
    }
    return ans;
  };
  auto karatsuba = [&](string x, string y, auto&& self) -> string {
    int n = max(sz(x), sz(y));
    if (n == 1) {
      int ans = (x[0] ^ '0') * (y[0] ^ '0');
      return to_string(ans);
    }
    if (n & 1) {
      x = '0' + x;
      y = '0' + y;
      ++n;
    }
    for (int i = 0; i < max(sz(x), sz(y)); i++) {
      if (sz(x) == sz(y)) break;
      if (sz(x) < sz(y)) x = '0' + x;
      else y = '0' + y;
    }
    int mid = (n >> 1);
    string a = x.substr(0, mid);
    string b = x.substr(mid);
    string c = y.substr(0, mid);
    string d = y.substr(mid);
    string ac = self(a, c, self);
    string bd = self(b, d, self);
    string abcd = self(add(a, b), add(c, d), self);
    string adbc = sub(sub(abcd, ac), bd); // abcd - ac - bd
    for (int i = 0; i < (mid << 1); i++) ac += '0';
    for (int i = 0; i < mid; i++) adbc += '0';
    string ans = add(add(ac, adbc), bd); // adbc + ac + bd
    return ans;
  };
  auto binpow = [&](string a, int m) {
    string res = "1";
    while (m) {
      if (m & 1) res = karatsuba(res, a, karatsuba);
      a = karatsuba(a, a, karatsuba);
      m >>= 1;
    }
    while (sz(res) > 1 && res[0] == '0') res.erase(0, 1);
    return res;
  };
  cout << binpow(a, m);

  return 0;
}