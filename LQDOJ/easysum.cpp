#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  long long ans;
  if (n & 1) {
    ans = -(n / 2) + n;
  } else ans = -(n / 2);
  cout << ans;
  return 0;
}