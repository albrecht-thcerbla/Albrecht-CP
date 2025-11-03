#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;

const int MAXM = 1005;
const int MAXN = 1005;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  int m, n;
  cin >> m >> n;
  vector<int> a(m + 1), b(n + 1);
  for (int i = 1; i <= m; i++) cin >> a[i];
  for (int j = 1; j <= n; j++) cin >> b[j];
  vector<int> pa(m + 1), pb(n + 1);
  for (int i = 1; i <= m; i++) pa[i] = pa[i - 1] + a[i];
  for (int j = 1; j <= n; j++) pb[j] = pb[j - 1] + b[j];
  auto sa = [&](int i, int k) {
    return pa[i + k - 1] - pa[i - 1];
  };
  auto sb = [&](int j, int k) {
    return pb[j + k - 1] - pb[j - 1];
  };
  int64_t ans = 0;
  auto scan_diag = [&](int i, int j) {
    int len = 0;
    for (; i <= m && j <= n; i++, j++) {
      if (a[i] == b[j] && a[i] != 0) {
        len++;
        for (int k = 1; k <= len; k++) {
          if (sa(i - k + 1, k) == 0 && sb(j - k + 1, k) == 0) ans++;
        }
      } else len = 0;
    }
  };
  for (int off = 0; off < n; off++) scan_diag(1, off + 1);
  for (int off = 1; off < m; off++) scan_diag(off + 1, 1);
  cout << ans << "\n";
  return 0;
}