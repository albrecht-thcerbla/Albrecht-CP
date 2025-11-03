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
    int64_t l, r; cin >> l >> r;
    int n = int(r - l + 1);
    vector<int> ans(n, -1);
    vector<char> used(n, 0);
    for (int bit = 30; ~bit; --bit) {
      int64_t s = int64_t(1) << bit;
      if (!s) continue;
      int64_t st = (l >> bit) << bit;
      for (; st <= r; st += s) {
        int64_t bl = max(l, st);
        int64_t br = min(r, st + s - 1);
        for (int64_t v = br; v >= bl; v--) {
          int idxv = int(v - l);
          if (used[idxv]) continue;
          int64_t t = v - st;
          int64_t y = st + ((s - 1) ^ t);
          if (y < bl || y > br) continue;
          int idxy = int(y - l);
          if (used[idxy]) continue;
          used[idxv] = used[idxy] = 1;
          ans[idxv] = idxy;
          ans[idxy] = idxv;
        }
      }
    }
    for (int i = 0; i < n; i++) if (ans[i] == -1) ans[i] = i;
    int64_t sum = 0;
    for (int i = 0; i < n; i++) {
      int64_t a = l + ans[i];
      int64_t b = l + i;
      sum += (a | b);
    }
    cout << sum << '\n';
    for (int i = 0; i < n; i++) cout << (l + ans[i]) << " ";
    cout << '\n';
  }
  return 0;
}