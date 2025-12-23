#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
const int64_t inf = 1e18;

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cin.exceptions(cin.failbit);
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  int tt; cin >> tt;
  while (tt--) {
    int n, k, x; cin >> n >> k >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(all(a));
    auto calc = [&](int d) -> bool {
      if (!d) return (x + 1 >= k);
      int f = 0, emp = 1, L = 0, R = 0;
      for (int i = 0; i < n; i++) {
        int l = a[i] - (d - 1);
        int r = a[i] + (d - 1);
        if (r < 0 || l > x) continue;
        l = max(l, 0);
        r = min(r, x);
        if (emp) {
          L = l; R = r; emp = false;
        } else if (l <= R + 1) R = max(R, r);
        else {
          f += (R - L + 1);
          L = l; R = r;
        }
      }
      if (!emp) f += (R - L + 1);
      return ((x + 1 - f) >= k);
    };
    int l = 0, r = x + 1;
    while (l < r) {
      int m = (l + r) >> 1;
      if (calc(m)) l = m + 1;
      else r = m;
    }
    int d = l - 1;
    vector<array<int, 2>> seg;
    if (d >= 1) {
      for (int i = 0; i < n; i++) {
        int l = a[i] - (d - 1);
        int r = a[i] + (d - 1);
        if (r < 0 || l > x) continue;
        l = max(l, 0);
        r = min(r, x);
        if (seg.empty() || l > seg.back()[1] + 1) seg.push_back({l, r});
        else seg.back()[1] = max(seg.back()[1], r);
      }
    }
    vector<int> ans;
    int cur = 0;
    for (int i = 0; i < sz(seg); i++) {
      for (int j = cur; j < seg[i][0] && sz(ans) < k; j++) ans.emplace_back(j);
      cur = seg[i][1] + 1;
      if (sz(ans) >= k) break;
    }
    for (int i = cur; i <= x && sz(ans) < k; i++) ans.emplace_back(i);
    for (int i = 0; i < sz(ans); i++) cout << ans[i] << " ";
    cout << '\n';
  }
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}