#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int64_t n; cin >> n;
  vector<int64_t> f, used;
  f.emplace_back(1); f.emplace_back(2);
  while (true) {
    int64_t cur = f[sz(f) - 1] + f[sz(f) - 2];
    if (cur > n) break;
    f.emplace_back(cur);
  }
  int64_t rem = n;
  for (int i = sz(f) - 1; ~i && rem; --i) {
    if (f[i] <= rem) {
      rem -= f[i];
      used.emplace_back(f[i]);
    }
  }
  if (used.empty()) cout << 0 << '\n';
  else cout << used.back() << '\n';
  return 0;
}