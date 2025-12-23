#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  string s; cin >> s;
  s += 'L';
  vector<int> v;
  long long num = 0;
  for (int i = 0; i < sz(s); i++) {
    if (s[i] >= '0' && s[i] <= '9') {
      if (s[i] == '0' && i == 0) continue;
      if (s[i] == '0' && s[i - 1] < '0' && s[i - 1] > '9') continue;
      (num *= 10) += (s[i] ^ '0');
    } else {
      if (num != 0) v.emplace_back(num);
      num = 0;
    }
  }
  sort(all(v));
  cout << v[sz(v) - 1] << '\n';
  long long sum = 0;
  for (int i = 0; i < sz(v); i++) sum += v[i];
  cout << sum << '\n';
  return 0;
}