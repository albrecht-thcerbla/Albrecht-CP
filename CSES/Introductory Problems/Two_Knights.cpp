#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  for (int k = 1; k <= n; k++) {
    long long cnt = 1ll + (k - 1) * (k - 2) / 2;
    cnt = cnt * (k - 1) * (k + 4);
    cout << cnt << '\n';
  }
  return 0;
}