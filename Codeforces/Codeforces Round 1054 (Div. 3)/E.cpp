#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  int tt; cin >> tt;
  while (tt--) {
    int n, k, l, r; cin >> n >> k >> l >> r;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    map<int, int> f1, f2;
    int l1 = 0, l2 = 0;
    int64_t ans = 0;
    for (int i = 0; i < n; i++) {
      f1[a[i]]++; f2[a[i]]++;
      while (sz(f1) > k) {
        if (--f1[a[l1]] == 0) f1.erase(a[l1]);
        l1++;
      }
      while (sz(f2) > k - 1) {
        if (--f2[a[l2]] == 0) f2.erase(a[l2]);
        l2++;
      }
      int mn = l, mx = r;
      int low = max(l1, i - mx + 1);
      int high = min(l2 - 1, i - mn + 1);
      if (high >= low) ans += (high - low + 1);
    }
    cout << ans << '\n';
  }  
  return 0;
}