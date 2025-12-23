#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;

int n;

void gene(string s) {
  if (sz(s) == n) {
    for (int i = 0; i < sz(s); i++) cout << s[i];
    cout << '\n';
    return;
  }
  gene(s + '0');
  gene(s + '1');
}
int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  gene("0");
  gene("1");
  return 0;
}