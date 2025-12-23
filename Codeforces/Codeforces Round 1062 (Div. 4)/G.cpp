#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define int int64_t

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
const int64_t inf = 1e18;

vector<int> bit;
void upd(int n, int i, int val) {
  for (; i <= n; i += i & -i) bit[i] = max(bit[i], val);
}
int get(int i) {
  int res = 0;
  for (; i > 0; i -= i & -i) res = max(res, bit[i]);
  return res;
}
int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cin.exceptions(cin.failbit);
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output1.out", "w", stdout);
  int tt; cin >> tt;
  while (tt--) {
    int n; cin >> n;
    vector<int> a(n), c(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int sumc = 0;
    for (int i = 0; i < n; i++) cin >> c[i], sumc += c[i];
    vector<int> b = a;
    sort(all(b));
    b.erase(unique(all(b)), b.end());
    bit.assign(sz(b) + 1, 0);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int idx = lower_bound(all(b), a[i]) - b.begin() + 1;
      int pref = get(idx);
      int dp = pref + c[i];
      ans = max(ans, dp);
      upd(sz(b), idx, dp);
    }
    cout << (sumc - ans) << '\n';
  }
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}