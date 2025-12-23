#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;

struct ST {
  int n;
  vector<int64_t> t;
  ST(int n = 0): n(n), t(n << 1, 0) {}
  void build(vector<int64_t> a) {
    for (int i = 0; i < n; i++) t[i + n] = a[i + 1];
    for (int i = n - 1; i; --i) t[i] = __gcd(t[i << 1], t[i << 1 | 1]);
  }
  int64_t get(int l, int r) {
    int64_t resl = 0, resr = 0;
    for (l += n - 1, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) resl = __gcd(resl, t[l++]);
      if (r & 1) resr = __gcd(t[--r], resr);
    }
    return __gcd(resl, resr);
  }
};
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("D:\\Albrecht-CP 2025\\input.inp", "r", stdin);
  freopen("D:\\Albrecht-CP 2025\\output.out", "w", stdout);
  int n, q; cin >> n >> q;
  vector<int64_t> a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  ST seg(n);
  seg.build(a);
  while (q--) {
    int l, r; cin >> l >> r;
    int64_t d; cin >> d;
    int64_t ans = 0;
    for (int start = l; start <= r; start++) {
      int low = start, high = r, pos = r + 1;
      while (low <= high) {
        int mid = (low + high) >> 1;
        int64_t g = seg.get(start, mid);
        if (g <= d) {
          pos = mid;
          high = mid - 1;
        } else low = mid + 1;
      }
      if (pos <= r) ans += (r - pos + 1);
    }
    cout << ans << '\n';
  }
  return 0;
}