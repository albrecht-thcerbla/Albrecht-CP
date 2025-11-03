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
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(all(a));
    int64_t base = 0;
    vector<int> extras; extras.reserve(n);
    for (int i = 0, j = i; i < n; i = j) {
      while (j < n && a[i] == a[j]) ++j;
      int cnt = j - i;
      base += int64_t(a[i] >> 1) * int64_t(cnt);
      if (a[i] & 1) extras.emplace_back(cnt);
    }
    sort(all(extras), greater<int>());
    array<int64_t, 2> ans{base, base};
    for (int i = 0; i < sz(extras); i++) ans[i & 1] += extras[i];
    cout << ans[0] << " " << ans[1] << '\n';
  }
  return 0;
}