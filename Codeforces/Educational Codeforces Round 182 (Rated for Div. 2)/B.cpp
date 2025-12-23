#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  int tt; cin >> tt;
  while (tt--) {
    int n; cin >> n;
    vector<int> a(n + 1), pre(n + 1, 0), zeros, missing;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if (!a[i]) zeros.emplace_back(i);
      else pre[a[i]] = 1;
    }
    for (int i = 1; i <= n; i++) if (!pre[i]) missing.emplace_back(i);
    int minfix = n + 1, maxfix = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] && a[i] != i) {
        minfix = min(minfix, i);
        maxfix = max(maxfix, i);
      }
    }
    int z = sz(zeros);
    int ans = 0;
    if (!z) {
      if (!maxfix) ans = 0;
      else ans = maxfix - minfix + 1;
    } else if (z >= 2) {
      int mn = n + 1, mx = 0;
      if (maxfix) {
        mn = minfix;
        mx = maxfix;
      }
      mn = min(mn, zeros.front());
      mx = max(mx, zeros.front());
      mn = min(mn, zeros.back());
      mx = max(mx, zeros.back());
      ans = mx - mn + 1;
    } else { // z = 1
      int pos = zeros[0];
      int miss = missing[0];
      int mn = n + 1, mx = 0;
      if (maxfix) {
        mn = minfix;
        mx = maxfix;
      }
      if (miss != pos) {
        mn = min(mn, pos);
        mx = max(mx, pos);
      }
      if (!mx) ans = 0;
      else ans = mx - mn + 1;
    }
    cout << ans << '\n';
  }
  return 0;
}