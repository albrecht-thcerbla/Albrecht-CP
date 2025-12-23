#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int64_t n; cin >> n;
  int64_t ans = 0;
  for (int64_t p = 5; p <= n; p *= 5) ans += (n / p);
  cout << ans << '\n';
  return 0;
}