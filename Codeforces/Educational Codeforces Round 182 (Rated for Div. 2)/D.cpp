#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int maxn = 2e5 + 7;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  int tt; cin >> tt;
  while (tt--) {
    int n; cin >> n;
    int64_t y; cin >> y;
    vector<int> c(n);
    int maxc = 0;
    for (int i = 0; i < n; i++) {
      cin >> c[i];
      maxc = max(maxc, c[i]);
    }
    vector<int> Old(maxc + 1, 0), pref(maxc + 1, 0);
    for (auto v : c) Old[v]++;
    for (int i = 1; i <= maxc; i++) pref[i] = pref[i - 1] + Old[i];
    int64_t best = LLONG_MIN;
    for (int x = 2; x <= max(2, maxc); x++) {
      int64_t sum = 0, need = 0;
      int K = (maxc + x - 1) / x;
      for (int p = 1; p <= K; p++) {
        int L = (p - 1) * x + 1;
        int R = min(p * x, maxc);
        if (L > R) continue;
        int cnt = pref[R] - pref[L - 1];
        if (!cnt) continue;
        sum += 1LL * cnt * p;
        if (p <= maxc) {
          if (cnt > Old[p]) need += 1LL * (cnt - Old[p]);
        } else {
          need += cnt;
        }
      }
      int64_t income = sum - need * y;
      if (income > best) best = income;
    }
    cout << best << '\n';
  }
  return 0;
}
