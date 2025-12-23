#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define int int64_t

const int mod = 1000000007;
const int maxn = 100000 + 7;
const int64_t inf = (int64_t)1e18;

const int MOD = 1000003;

vector<int> fact, ifact;

int modpow(int a, int e) {
  int r = 1, x = a;
  while (e) {
    if (e & 1) r = (r * x) % MOD;
    x = (x * x) % MOD;
    e >>= 1;
  }
  return r;
}
void build_fact() {
  fact.assign(MOD, 0);
  ifact.assign(MOD, 0);
  fact[0] = 1;
  for (int i = 1; i < MOD; i++) fact[i] = fact[i - 1] * i % MOD;
  ifact[MOD - 1] = modpow(fact[MOD - 1], MOD - 2);
  for (int i = MOD - 2; i >= 0; i--) ifact[i] = ifact[i + 1] * (i + 1) % MOD;
}
int nCk(int n, int k) {
  if (k < 0 || k > n) return 0;
  int r = 1;
  while (n > 0 || k > 0) {
    int ni = n % MOD;
    int ki = k % MOD;
    if (ki > ni) return 0;
    r = r * fact[ni] % MOD * ifact[ki] % MOD * ifact[ni - ki] % MOD;
    n /= MOD;
    k /= MOD;
  }
  return r;
}

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cin.exceptions(cin.failbit);
  build_fact();
  int tt; cin >> tt;
  while (tt--) {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    int dmax = 60;
    for (int i = 0; i < n; i++) {
      int r = b[i] / a[i];
      int t = 0;
      while ((1 << t) <= r && t < 60) t++;
      t = max(int64_t(0), t - 1);
      dmax = min(dmax, t);
    }
    int best = inf;
    int ans = 0;
    for (int d = 0; d <= dmax; d++) {
      bool ok = true;
      int hsum = 0, pc = 0;
      vector<int> h(n);
      vector<int> ms(d + 1, 0);
      for (int i = 0; i < n; i++) {
        int as = a[i] * (1 << d);
        if (as > b[i]) {
          ok = false;
          break;
        }
        int dt = b[i] - as;
        int hi = dt >> d;
        int lo = dt & ((d >= 62) ? -1LL : ((1 << d) - 1));
        h[i] = hi;
        hsum += hi;
        pc += __builtin_popcountll(lo);
        for (int p = 0; p < d; p++)
          if ((lo >> p) & 1) ms[d - p]++;
      }
      if (!ok) continue;
      int ops = d + hsum + pc;
      if (ops > best) continue;
      int w = 1;
      for (int s = 1; s <= d; s++) {
        int c = ms[s];
        (w *= fact[c]) %= MOD;
      }
      int rem = hsum;
      for (int i = 0; i < n; i++) {
        if (h[i]) {
          int c = nCk(rem, h[i]);
          (w *= c) %= MOD;
          rem -= h[i];
        }
      }
      if (ops < best) {
        best = ops;
        ans = w;
      } else if (ops == best) {
        (ans += w) %= MOD;
      }
    }
    cout << best << " " << ans << '\n';
  }
  return 0;
}

