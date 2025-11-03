#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;

/**
 * Call dp[i] = the maximum amount of money earned if box i-th is chosen as the starting point.
 * Start at a[i], after that (i + 1) -> (i + k).
 * => dp[i] = a[i] + max(0, dp[j])) with j from (i + 1) to (i + k).
 * means dp[i] = a[i] + max(0, dp[i + 1],..dp[i + 2],..dp[i + k]).
 * => answer = max(dp[i]) with i from 1 -> n.
 * 
 * */
int n, k;
vector<int64_t> a, t, dp;

void build() {
  for (int i = 0; i < n; i++) t[i + n] = a[i];
  for (int i = n - 1; i > 0; i--) t[i] = max(t[i << 1], t[i << 1 | 1]);
}
void modify(int p, int64_t val) {
  for (t[p += n] = val; p > 1; p >>= 1) t[p >> 1] = max(t[p], t[p ^ 1]);
}
int64_t get(int l, int r) {
  int64_t res = -1e18;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1) res = max(res, t[l++]);
    if (r & 1) res = max(res, t[--r]);
  }
  return res;
}
int32_t main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> k;
  a.resize(n); t.resize(n << 1); dp.assign(n, 0);
  for (int i = 0; i < n; i++) cin >> a[i];
  build();
  for (int i = n - 1; ~i; --i) {
    if (i + k >= n) {
      int64_t mx = get(i + 1, n);
      dp[i] = max(mx, (int64_t)0) + (int64_t)1 * a[i];
      modify(i, dp[i]);
    } else {
      int64_t mx = get(i + 1, i + k + 1);
      dp[i] = max(mx, (int64_t)0) + (int64_t)1 * a[i];
      modify(i, dp[i]);
    }
  }
  int64_t ans = 0;
  ans = max(ans, *max_element(all(dp)));
  cout << ans << '\n';
  return 0;
}