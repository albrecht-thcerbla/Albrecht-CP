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
    int n, k; cin >> n >> k;
    vector<int64_t> a(n), b(k);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < k; i++) cin >> b[i];
    sort(a.rbegin(), a.rend());
    sort(all(b));
    int64_t ans = 0;
    int idx = 0;
    for (int i = 0; i < k; i++) {
      int x = b[i];
      if (idx + x > n) break; // ko du sp
      for (int j = 0; j < x - 1; j++) ans += a[idx++]; // + them (x - 1) sp expensive nhat
      ++idx;
    }
    while (idx < n) ans += a[idx++];
    cout << ans << '\n';
  }
  return 0;
}