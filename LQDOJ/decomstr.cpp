#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  string s; cin >> s;
  vector<int> num;
  for (int i = 0; i < sz(s); i++) {
    int number = 1;
    if (s[i] >= '0' && s[i] <= '9') {
      if (!num.empty()) {
        num[0] = num[0] * 10 + (s[i] ^ '0');
        continue;
      }
      number = s[i] ^ '0';
      num.emplace_back(number);
    } else {
      if (num.empty()) {
        cout << s[i];
      } else {
        int tmp = num[0];
        num.clear();
        for (int j = 0; j < tmp; j++) cout << s[i];
      }
    }
  }
  return 0;
}