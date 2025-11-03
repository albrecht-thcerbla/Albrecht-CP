#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;

// 1 2
// 1 1

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, x; cin >> n >> x;
  bool ok = true;
  vector<int> a(n + 1);
  for (int i = 0; i < n; i++) cin >> a[i];
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    if (ok) {
      if (mp.find(x - a[i]) != mp.end()) {
        cout << mp[x - a[i]] << " " << i + 1 << '\n';
        ok = false;
      }
    }
    mp.insert({a[i], i + 1});
  }
  if (ok) cout << "IMPOSSIBLE" << '\n';
  return 0;
}