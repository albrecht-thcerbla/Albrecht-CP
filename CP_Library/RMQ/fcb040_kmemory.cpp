#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
const int64_t inf = 1e18;

int mi[21][maxn], mx[21][maxn];

int get(int l, int r, int ty) {
  int k = log2(r - l + 1);
  if (ty == 1) return min(mi[k][l], mi[k][r - (1 << k) + 1]);
  return max(mx[k][l], mx[k][r - (1 << k) + 1]);
}
int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cin.exceptions(cin.failbit);
  int n, k; cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    mi[0][i] = mx[0][i] = x;
  }
  for (int l = 1; (1 << l) <= n; l++) {
    for (int i = 1; i + (1 << l) - 1 <= n; i++) {
      mi[l][i] = min(mi[l - 1][i], mi[l - 1][i + (1 << l - 1)]);
      mx[l][i] = max(mx[l - 1][i], mx[l - 1][i + (1 << l - 1)]);
    }
  }
  int ans = 0;
  for (int l = 1; l <= n; l++) {
    int low = l - 1, high = n + 1;
    while (high - low > 1) {
      int mid = (low + high) >> 1;
      if (get(l, mid, 0) - get(l, mid, 1) <= k) low = mid;
      else high = mid;
    }
    ans += (low - l + 1);
  }
  cout << ans << '\n';
  cerr << '\n' << "Times: " << TIME << "s." << '\n';
  return 0;
}

