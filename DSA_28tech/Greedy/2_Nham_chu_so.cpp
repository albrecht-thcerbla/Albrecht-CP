#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

long long mx(string a, string b) {
  for (int i = 0; i < sz(a); i++) if (a[i] == '5') a[i] = '6';
  for (int i = 0; i < sz(b); i++) if (b[i] == '5') b[i] = '6';
  long long x = stoll(a);
  long long y = stoll(b);
  return x + y;
}

long long mn(string a, string b) {
  for (int i = 0; i < sz(a); i++) if (a[i] == '6') a[i] = '5';
  for (int i = 0; i < sz(b); i++) if (b[i] == '6') b[i] = '5';
  long long x = stoll(a);
  long long y = stoll(b);
  return x + y;
}
int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  string a, b; cin >> a >> b;
  cout << mx(a, b) << " " << mn(a, b) << '\n';
  return 0;
}