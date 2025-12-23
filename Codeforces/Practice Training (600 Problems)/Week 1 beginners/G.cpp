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
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(all(a));
  int k = (n - 1) >> 1;
  cout << k << '\n';
  vector<int> ans(n);
  int small = 0, large = k;
  for (int i = 0; i < n; i++) {
    if (i & 1 && small < k) ans[i] = a[small++];
    else ans[i] = a[large++];
  }
  for (int i = 0; i < n; i++) cout << ans[i] << " ";
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}