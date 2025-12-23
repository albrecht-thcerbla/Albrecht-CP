#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  vector<int64_t> a(n), lis;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    int64_t x = -a[i];
    auto it = upper_bound(all(lis), x);
    if (it == lis.end()) lis.emplace_back(x);
    else *it = x;
  }
  cout << sz(lis) << '\n';
  return 0;
}